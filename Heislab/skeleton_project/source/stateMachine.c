#include "stateMachine.h"

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
int state_stationary(int *em_queue, int *em_nextFloor, int *em_currentFloor, int *MotorDirection){

    while (1) {
        elevio_motorDirection(DIRN_STOP);
        em_getNextFloor(em_nextFloor);
        em_getCurrentFloor(em_currentFloor);

        if (elevio_stopButton() == 1) {
            // Clear EM
            state_openDoor(em_queue, em_nextFloor, em_currentFloor, MotorDirection);
        }

        if ((*em_nextFloor != -1) && (*em_nextFloor != *em_currentFloor)) {
            break;
        }
    }
    return 0;
}

// Tilstand hvor heisen beveger seg
int state_move(int *em_queue, int *em_nextFloor, int *em_currentFloor, int *MotorDirection){

    em_getNextFloor(em_nextFloor);
    em_getCurrentFloor(em_currentFloor);

    while (em_nextFloor > em_currentFloor) {
        elevio_motorDirection(DIRN_UP);
        if (elevio_floorSensor() != -1) {
            em_getCurrentFloor(em_currentFloor);
        }
        if (elevio_stopButton() == 1) {
            elevio_motorDirection(DIRN_STOP);
            return 1;
        }
        em_getNextFloor(em_nextFloor);
    }

    while (em_nextFloor < em_currentFloor) {
        elevio_motorDirection(DIRN_DOWN);
        em_getCurrentFloor(em_currentFloor);
        if (elevio_stopButton() == 1) {
            elevio_motorDirection(DIRN_STOP);
            return 1;
        }
        em_getNextFloor(em_nextFloor);
    }
    return 0;
}

// Tilstand hvor heisen står stille med åpen dør
int state_openDoor(int *em_queue, int *em_nextFloor, int *em_currentFloor, int *MotorDirection){

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
            printf("Obstruction activated\n");
        }

    }
    printf("Timer done\n");
    return 1;
}

