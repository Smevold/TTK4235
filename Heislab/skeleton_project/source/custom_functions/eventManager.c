#include "eventManager.h"

// Clear funksjon - tømmer historikken og setter nextFloor lik -1

int em_checkBtnPressed() {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            int btnPressed = elevio_callButton(f,b);
            elevio_buttonLamp(f, b, btnPressed);
            if(btnPressed == 1) {
                return f;
            }
        }
    }
    return -1;
}

void em_getCurrentFloor(int *currentFloor) {
    int newFloor = elevio_floorSensor();
    if (newFloor != -1) {
        *currentFloor = newFloor;
    }
}

void em_getNextFloor(int *nextFloor) {
    int tempFloor = em_checkBtnPressed();
    if (tempFloor != -1) {
        *nextFloor = tempFloor;
    }
};