#include "lights.h"

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