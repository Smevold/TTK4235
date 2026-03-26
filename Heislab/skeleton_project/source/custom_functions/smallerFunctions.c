#include "smallerFunctions.h"

void mDirUp(int *MotorDirection){
    elevio_motorDirection(DIRN_UP);
    *MotorDirection = 1;
}
void mDirDown(int *MotorDirection){
    elevio_motorDirection(DIRN_DOWN);
    *MotorDirection = -1;
}
void mDirStop(int *MotorDirection){
    elevio_motorDirection(DIRN_STOP);
}

void lights_floorOffCurrent(int* em_currentFloor) {
    // Skrur av lysene i etasjen
    for (int b = 0; b < 3; b++) {
        elevio_buttonLamp(*em_currentFloor, b, 0);
    }
}

void lights_floorOffAll() {
    // Skrur av alle lys
        for (int f = 0; f < N_FLOORS; f++) {
            // Skrur av lysene i etasjen
            for (int b = 0; b < 3; b++) {
                elevio_buttonLamp(f, b, 0);
            }

        }
}