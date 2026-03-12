#include "driver/elevio.h"
#include "stateMachine.h"
#include <unistd.h>

/**
 * @file
 * @brief Main
 */

int main() {
    int stop            = 1;
    int em_nextFloor    = -1;
    int em_currentFloor = -1;
    int motorDirection  = 1;

    int em_queueUp[N_FLOORS];
    int em_queueDown[N_FLOORS];

    // NBNB! For bedre heis. Istedenfor alle disse verdiene som sendes inn i
    // basically alle funksjonene så lager vi heller en typedef enum elrno
    // (struct for array?) som er heisen vår, med alle variablene vi ellers
    // sender rundt omkring

    em_clear(em_queueUp, em_queueDown);

    state_startUp();

    /* int test = state_openDoor(em_queueUp, em_queueDown,
        &em_nextFloor, &em_currentFloor, &motorDirection
    );
    if (test == 1) {
        printf("Hurray\n");
    } else {
        printf("BUUUU\n");
    } */

    while (1) {
        while (stop != 1) {
            stop = state_move(em_queueUp, em_queueDown, &em_nextFloor,
                &em_currentFloor, &motorDirection);
            if (stop == 1) {
                break;
            }
            stop = state_openDoor(em_queueUp, em_queueDown, &em_nextFloor,
                &em_currentFloor, &motorDirection);
        }
        stop = state_stationary(em_queueUp, em_queueDown, &em_nextFloor,
            &em_currentFloor, &motorDirection);
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
