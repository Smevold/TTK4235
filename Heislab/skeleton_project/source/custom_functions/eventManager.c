#include "eventManager.h"

// Clear funksjon - tømmer historikken og setter nextFloor lik -1

int em_checkBtnPressed() {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            int btnPressed = elevio_callButton(f,b);
            elevio_buttonLamp(f, b, btnPressed);
            printf("f: %d, b: %d, btn: %d   |   \n", f, b, btnPressed);
            if(btnPressed == 1) {
                return f;
            }
        }
    }
    return -1;
}

int em_getCurrentFloor() {
    int floor = elevio_floorSensor();
    return floor;
}

int em_getNextFloor() {
    int em_tempFloor = em_checkBtnPressed();
    if (em_tempFloor != -1) {
        int ioTest_nextFloor = em_tempFloor;
    }
};