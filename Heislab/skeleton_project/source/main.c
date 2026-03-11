#include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <time.h>
#include "driver/elevio.h"
#include "stateMachine.h"
#include <unistd.h>

int main (){
    int stop = 1;
    int em_queue[N_FLOORS];
    int em_nextFloor = -1; int em_currentFloor = -1; int motorDirection = 0;

    em_clear(em_queue);

    state_startUp();

    /* int test = state_openDoor(em_queue, 
        &em_nextFloor, &em_currentFloor, 
        &motorDirection
    );
    if (test == 1) {
        printf("Hurray\n");
    } else {
        printf("BUUUU\n");
    } */

    while(1) {
        while (stop != 1) {
            stop = state_move(em_queue, 
                &em_nextFloor, &em_currentFloor, 
                &motorDirection
            );
            if (stop == 1) {
                break;
            }
            stop = state_openDoor(em_queue, 
                &em_nextFloor, &em_currentFloor, 
                &motorDirection
            );
        }
        stop = state_stationary(em_queue, 
            &em_nextFloor, &em_currentFloor, 
            &motorDirection
        );
    }
}

/* int main(){
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


