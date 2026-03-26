#include "stateMachine.h"
#include "custom_functions/eventManager.h"
#include "custom_functions/smallerFunctions.h"
#include "custom_functions/timer.h"
#include "driver/elevio.h"
#include <stdio.h>

#define NEXTFLOOR 1

// Kjøres kun en gang:
void state_startUp() {

    elevio_init(); // Initialisere IO

    printf("=== Program Starting ===\n");

    int floor = elevio_floorSensor();

    while (floor == -1) {

        floor = elevio_floorSensor();

        // Bruker denne dersom heisen skal kunne stoppes under initialisering
        /* if (elevio_stopButton() == 1) { // Hvis stoppknapp blir initiert
            elevio_motorDirection(DIRN_STOP);
            sleep(3); // Potensially change method later
        } else {
            elevio_motorDirection(DIRN_DOWN);
        } */
        elevio_motorDirection(DIRN_DOWN);
    }

    // Bruker denne dersom heisen *ikke* skal kunne stoppes under initialisering
    elevio_motorDirection(DIRN_STOP);
}

// Tilstand hvor heisen står stille
int state_stationary(int* em_queueUp, int* em_queueDown, int* em_nextFloor,
    int* em_currentFloor, int* motorDirection) {

    // printf("=== Entering Stationary State ===\n");

    while (1) {
        mDirStop(motorDirection);
        em_updateQueues(em_queueUp, em_queueDown);
        em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection,
            em_currentFloor);
        em_getCurrentFloor(em_currentFloor);
        // em_printQueue(em_nextFloor, em_currentFloor, motorDirection,
        // em_queueUp, em_queueDown);

        if (elevio_stopButton() == 1) {
            elevio_stopLamp(1);
            em_clear(em_queueUp, em_queueDown);
            state_openDoor(em_queueUp, em_queueDown, em_nextFloor,
                em_currentFloor, motorDirection);
            // printf("=== Entering Stationary State ===\n");
        }

        if ((*em_nextFloor != -1) && (*em_nextFloor != *em_currentFloor)) {
            break;
        }

        if ((*em_nextFloor != -1) &&
            (*em_currentFloor != elevio_floorSensor())) {
            *em_currentFloor += *motorDirection;
            break;
        } else if (*em_nextFloor == *em_currentFloor) {
            state_openDoor(em_queueUp, em_queueDown, em_nextFloor,
                em_currentFloor, motorDirection);
        }
    }
    return 0;
}

// Tilstand hvor heisen beveger seg
int state_move(int* em_queueUp, int* em_queueDown, int* em_nextFloor,
    int* em_currentFloor, int* motorDirection) {

    // printf("=== Entering Moving State ===\n");

    // em_updateQueues(em_queueUp, em_queueDown);
    // em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection,
    // em_currentFloor); em_getCurrentFloor(em_currentFloor);

    // em_printQueue(em_nextFloor, em_currentFloor, motorDirection, em_queueUp,
    //     em_queueDown);

    while (*em_nextFloor > *em_currentFloor) {

        mDirUp(motorDirection);

        em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection,
            em_currentFloor);

        em_getCurrentFloor(em_currentFloor);

        // printf("Moving Upwards\n");
        // em_printQueue(em_nextFloor, em_currentFloor, motorDirection,
        // em_queueUp,
        //     em_queueDown);

        em_updateQueues(em_queueUp, em_queueDown);
        em_getCurrentFloor(em_currentFloor);

        if (elevio_stopButton() == 1) {
            elevio_stopLamp(1);
            mDirStop(motorDirection);
            em_clear(em_queueUp, em_queueDown);
            state_openDoor(em_queueUp, em_queueDown, em_nextFloor,
                em_currentFloor, motorDirection);
            return 1;
        }
    }

    while (*em_nextFloor < *em_currentFloor) {

        mDirDown(motorDirection);

        em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection,
            em_currentFloor);

        em_getCurrentFloor(em_currentFloor);

        // printf("Moving Downwards\n");
        // em_printQueue(em_nextFloor, em_currentFloor, motorDirection,
        // em_queueUp,
        //     em_queueDown);

        em_updateQueues(em_queueUp, em_queueDown);
        em_getCurrentFloor(em_currentFloor);

        if (elevio_stopButton() == 1) {
            elevio_stopLamp(1);
            mDirStop(motorDirection);
            em_clear(em_queueUp, em_queueDown);
            state_openDoor(em_queueUp, em_queueDown, em_nextFloor,
                em_currentFloor, motorDirection);
            return 1;
        }
    }

    // printf("Exiting Moving State\n");

    return 0;
}

// Tilstand hvor heisen står stille med åpen dør
int state_openDoor(int* em_queueUp, int* em_queueDown, int* em_nextFloor,
    int* em_currentFloor, int* motorDirection) {

    if (elevio_stopButton() == 0) {
        elevio_stopLamp(0);
    }

    em_clearCurrentFloor(em_currentFloor, em_queueUp, em_queueDown);
    // em_printQueue(em_nextFloor, em_currentFloor, motorDirection, em_queueUp,
    //     em_queueDown);

    // printf("=== Entering Open Door State ===\n");

    if (elevio_floorSensor() != -1) {
        // printf("Opening the door\n");
        elevio_doorOpenLamp(1);
        // Lamp stuff
    }

    clock_t t_start, t_end;

    timer_start(&t_start, &t_end);

    mDirStop(motorDirection);

    // printf("The time is now: %lu\nAnd the time will be: %lu\n", t_start,
    // t_end);

    em_clearCurrentFloor(em_currentFloor, em_queueUp, em_queueDown);

    while (1) {

        if (elevio_stopButton() == 0) {
            elevio_stopLamp(0);
        }

        if (timer_isTimeOut(&t_start, &t_end)) {
            break;
        }

        // printf("The time is now: %lu\n", t_start);

        em_updateQueues(em_queueUp, em_queueDown);
        // em_printQueue(em_nextFloor, em_currentFloor, motorDirection,
        // em_queueUp,
        //     em_queueDown);
        em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection,
            em_currentFloor);
        // em_getCurrentFloor(em_currentFloor);

        if (elevio_stopButton() == 1) {
            elevio_stopLamp(1);
            timer_start(&t_start, &t_end);
            // printf("Stop Button activated\n");
            em_clear(em_queueUp, em_queueDown);
        } else if (elevio_obstruction() == 1) {
            timer_start(&t_start, &t_end);
            // printf("Obstruction activated\n");
        } else if (*em_nextFloor == *em_currentFloor) {
            timer_start(&t_start, &t_end);
            em_clearCurrentFloor(em_currentFloor, em_queueUp, em_queueDown);
            *em_nextFloor = -1;
            // printf("Opening door on same floor\n");
        }
    }
    // printf("Closing the Doors\n");
    elevio_doorOpenLamp(0);
    em_updateQueues(em_queueUp, em_queueDown);
    em_getNextFloor(em_nextFloor, em_queueUp, em_queueDown, motorDirection,
        em_currentFloor);
    em_getCurrentFloor(em_currentFloor);
    // em_printQueue(em_nextFloor, em_currentFloor, motorDirection, em_queueUp,
    //     em_queueDown);

    return 1;
}