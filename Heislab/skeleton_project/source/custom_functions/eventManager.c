#include "eventManager.h"

// Clear funksjon - tømmer historikken og setter nextFloor lik -1

int ioTest_getNextFloor() {
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

int ioTest_getCurrentFloor() {
    int floor = elevio_floorSensor();
    return floor;
}
