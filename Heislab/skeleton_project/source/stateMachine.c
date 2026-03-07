#include "stateMachine.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "custom_functions/timer.h"
#include "driver/elevio.h"
#include "custom_functions/eventManager.h"

#define NEXTFLOOR 1

// Kjøres kun en gang:
void state_startUp(){
    
    elevio_init(); //Initialisere IO

    printf("=== Program Starting ===\n");

    int floor = elevio_floorSensor();

    while (floor == -1) {

        floor = elevio_floorSensor();

        if (elevio_stopButton() == 1) { //Hvis stoppknapp blir initiert
            elevio_motorDirection(DIRN_STOP);
            sleep(3); // Potensially change method later
        } else {
            elevio_motorDirection(DIRN_DOWN);
        }
        
    
    }
    elevio_motorDirection(DIRN_STOP);
}

// Tilstand hvor heisen står stille
int state_stationary(){
    int em_nextFloor, em_currentFloor;
    while (1) {
        elevio_motorDirection(DIRN_STOP);
        em_nextFloor = em_getNextFloor();
        em_currentFloor = elevio_floorSensor(); // Hent current floor fra EM

        if (elevio_stopButton() == 1) {
            // Clear EM
            state_openDoor();
        }

        if ((em_nextFloor != -1) && (em_nextFloor != em_currentFloor)) {
            break;
        }
    }
    return 0;
}

int state_move(){
    int em_nextFloor = em_getNextFloor();
    int em_currentFloor = elevio_floorSensor(); // Hent current floor fra EM

    while (em_nextFloor > em_currentFloor) {
        elevio_motorDirection(DIRN_UP);
        if (elevio_floorSensor() != -1) {
            em_currentFloor = elevio_floorSensor();
        }
        if (elevio_stopButton() == 1) {
            elevio_motorDirection(DIRN_STOP);
            return 1;
        }
        em_nextFloor = em_getNextFloor();
    }

    while (em_nextFloor < em_currentFloor) {
        elevio_motorDirection(DIRN_DOWN);
        if (elevio_floorSensor() != -1) {
            em_currentFloor = elevio_floorSensor();
        }
        if (elevio_stopButton() == 1) {
            elevio_motorDirection(DIRN_STOP);
            return 1;
        }
        em_nextFloor = em_getNextFloor();
    }
    return 0;
}

int state_openDoor(){

    clock_t t_start, t_end;

    timer_start(&t_start,&t_end);

    elevio_motorDirection(DIRN_STOP);

    printf("The time is now: %lu\nAnd the time will be: %lu\n", t_start, t_end);

    int timeOut = timer_isTimeOut(&t_start, &t_end);

    while (timeOut == 0) {
        timeOut = timer_isTimeOut(&t_start, &t_end);

        if (elevio_stopButton() == 1) {
            timer_start(&t_start,&t_end);
            printf("Stop Button activated\n");
            // Clear EM
        } else if (elevio_obstruction() == 1) {
            timer_start(&t_start,&t_end);
            printf("obstruction activated\n");
        }

    }
    printf("Timer done\n");
    return 1;
}

