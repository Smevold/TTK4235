#include "stateMachine.h"
#include "custom_functions/eventManager.h"
#include "custom_functions/smallerFunctions.h"

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
int state_stationary(int *em_queueUp, int *em_queueDown, int *em_nextFloor, int *em_currentFloor, int *motorDirection){

    while (1) {
        mDirStop(motorDirection);
        em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection, em_currentFloor);
        em_getCurrentFloor(em_currentFloor);

        if (elevio_stopButton() == 1) {
            em_clear(em_queueUp, em_queueDown);
            state_openDoor(em_queueUp, em_queueDown, em_nextFloor, em_currentFloor, motorDirection);
        }

        if ((*em_nextFloor != -1) && (*em_nextFloor != *em_currentFloor)) {
            break;
        }
    }
    return 0;
}

// Tilstand hvor heisen beveger seg
int state_move(int *em_queueUp, int *em_queueDown, int *em_nextFloor, int *em_currentFloor, int *motorDirection){

    em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection, em_currentFloor);
    em_getCurrentFloor(em_currentFloor);

    while (em_nextFloor > em_currentFloor) {
        mDirUp(motorDirection);

        em_getCurrentFloor(em_currentFloor);

        if (elevio_stopButton() == 1) {
            mDirStop(motorDirection);
            return 1;
        }

        em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection, em_currentFloor);
    }

    while (em_nextFloor < em_currentFloor) {
        mDirDown(motorDirection);

        em_getCurrentFloor(em_currentFloor);

        if (elevio_stopButton() == 1) {
            mDirStop(motorDirection);
            return 1;
        }

        em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection, em_currentFloor);
    }
    return 0;
}

// Tilstand hvor heisen står stille med åpen dør
int state_openDoor(int *em_queueUp, int *em_queueDown, int *em_nextFloor, int *em_currentFloor, int *motorDirection){

    clock_t t_start, t_end;

    timer_start(&t_start,&t_end);

    mDirStop(motorDirection);

    printf("The time is now: %lu\nAnd the time will be: %lu\n", t_start, t_end);

    int timeOut = timer_isTimeOut(&t_start, &t_end);

    while (timeOut == 0) {
        timeOut = timer_isTimeOut(&t_start, &t_end);



        if (elevio_stopButton() == 1) {
            timer_start(&t_start,&t_end);
            printf("Stop Button activated\n");
            em_clear(em_queueUp, em_queueDown);
        } else if (elevio_obstruction() == 1) {
            timer_start(&t_start,&t_end);
            printf("Obstruction activated\n");
        }

    }
    printf("Timer done\n");
    return 1;
}

