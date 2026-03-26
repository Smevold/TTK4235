#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "driver/elevio.h"


void ioTest_startUp() {
    elevio_init();

    printf("=== Augusts IO-tester===");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(DIRN_UP);

    // Finding a floor
    while(1) {
        int floor = elevio_floorSensor();

        if (floor != -1) {
            elevio_motorDirection(DIRN_STOP);
            break;
        }
    }
}

/**
* @brief Sjekker hvilken etasje heisen er i
*/
int ioTest_getCurrentFloor() {
    int floor = elevio_floorSensor();
    return floor;
}


/**
* @brief Sjekker hvilke knakker som blir trykket
* @param[out] f Hvilken etasje som har blitt trykket på, der @p f er nullindeksert
*
* @warning Dersom @p f er lik -1, skal dette telle som at ingen etasjeknapp er trykket på
*/
int ioTest_getNextFloor() {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            int btnPressed = elevio_callButton(f,b);
            elevio_buttonLamp(f, b, btnPressed);
            if(btnPressed == 1) {
                printf("f: %d, b: %d, btn: %d   |   \n", f, b, btnPressed);
                return f;
            }
        }
    }
    return -1;
}

int main() {
    ioTest_startUp();

    // Variabeldeklarasjoner
    int ioTest_tempFloor = 0;
    int ioTest_currentFloor = 0;
    int ioTest_nextFloor = 0;

    while(1) {
        ioTest_tempFloor = ioTest_getNextFloor();
        if (ioTest_tempFloor != -1) {
            ioTest_nextFloor = ioTest_tempFloor;
        }
        ioTest_currentFloor = ioTest_getCurrentFloor();

        printf("n: %d, c: %d\n", ioTest_nextFloor, ioTest_currentFloor);

        // Simplifisert statemachine
        if(ioTest_currentFloor == -1) {
            continue;
        } else if (ioTest_nextFloor > ioTest_currentFloor) {
            elevio_motorDirection(DIRN_UP);
        } else if (ioTest_nextFloor < ioTest_currentFloor) {
            elevio_motorDirection(DIRN_DOWN);
        } else {
            elevio_motorDirection(DIRN_STOP);
        }

        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }

        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }


    return 0;
}


/* Original main som fulgte med filen
    
    int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(DIRN_UP);

    while(1){
        int floor = elevio_floorSensor();

        if(floor == 0){
            elevio_motorDirection(DIRN_UP);
        }

        if(floor == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
        }


        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
} */
