#include "eventManager.h"

// Clear funksjon - tømmer historikken og setter nextFloor lik -1
void em_clear(int *em_queue) {
    for(int i = 0; i < N_FLOORS; ++i) {
        em_queue[i] = -1;
    }
}

// Sjekker hvilken knapp som er trykket på
int em_checkBtnPressed() { // GJØR F OG B OM TIL PASS BY REFERENCE
    // Itererer gjennom alle knappene
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            int btnPressed = elevio_callButton(f,b);
            elevio_buttonLamp(f, b, btnPressed);

            // Returnerer kun dersom en knapp blir trykket på
            if(btnPressed == 1) {
                return f; // Vil også returnere b (som pass by)
            }
        }
    }
    return -1;
}

// Oppdaterer currentFloor dersom den faktisk er ved en etasje
void em_getCurrentFloor(int *currentFloor) {
    int newFloor = elevio_floorSensor();

    // Vil kun oppdatere dersom heisen faktisk er ved en etasje
    if (newFloor != -1) {
        *currentFloor = newFloor;
    }
}

void em_getNextFloor(int *nextFloor) {
    int f = em_checkBtnPressed();

    // Vil ikke oppdatere listen dersom f = -1, for ingen knapp har blitt trykket
    if (f == -1) {
        return;
    }
};