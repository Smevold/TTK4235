#include "eventManager.h"

// Clear funksjon - tømmer historikken og setter nextFloor lik -1
void em_clear(int* em_queueUp, int* em_queueDown) {
    for (int i = 0; i < N_FLOORS; ++i) {
        em_queueUp[i] = 0;
        em_queueDown[i] = 0;
    }
}

// Sjekker hvilken knapp som er trykket på
void em_checkBtnPressed(int* floor, int* btn) {
    // Itererer gjennom alle knappene
    for (int f = 0; f < N_FLOORS; f++) {
        for (int b = 0; b < N_BUTTONS; b++) {
            int btnPressed = elevio_callButton(f, b);
            elevio_buttonLamp(f, b, btnPressed);

            // Endrer verdi kun dersom en knapp blir trykket på
            if (btnPressed == 1) {
                *floor = f;
                *btn = b;
                return;
            }
        }
    }
}

// Oppdaterer currentFloor dersom den faktisk er ved en etasje
void em_getCurrentFloor(int* em_currentFloor) {
    int newFloor = elevio_floorSensor();

    // Vil kun oppdatere dersom heisen faktisk er ved en etasje
    if (newFloor != -1) {
        *em_currentFloor = newFloor;
    }
}

// Skal fjerne etasjen fra køen idet den når en etasje, ikke oftere! (kan være
// vanskelig med vår implementasjon?)
void em_clearCurrentFloor(int* em_currentFloor, int* em_queueUp,
                          int* em_queueDown) {

    // Clears queue for both directions
    em_queueUp[*em_currentFloor] = 0;
    em_queueDown[*em_currentFloor] = 0;
}

// int* em_queueUp[4] = {0,0,0,0};
// int* em_queueDown[4] = {0,0,0,0};

// Oppdaterer køene, burde kjøres kontinuerlig for denne er den som merker om en
// knapp blir trykket
void em_updateQueues(int* em_queueUp, int* em_queueDown) {
    int f = -1;
    int b = -1;

    em_checkBtnPressed(&f, &b);

    // Vil ikke oppdatere listen dersom f = -1, for ingen knapp har blitt
    // trykket
    if (f == -1) {
        return;
    }

    // Sjekker hvilken retning knappen skal
    if (b == 0) {
        // Legg til i oppover
        em_queueUp[f] = 1;
    } else if (b == 1) {
        // Legg til i nedover
        em_queueDown[f] = 1;
    } else {
        // b == 2
        // Legg til i begge etasjer (fordi du vil stoppe i denne etasjen
        // uavhengig av heisens retning)
        em_queueUp[f] = 1;
        em_queueDown[f] = 1;
    }
}

// int* em_queueUp[4] = {0,0,0,0};
// int* em_queueDown[4] = {0,0,0,0};

// Endrer nextFloor til den neste etasjen, ved å se gjennom listene basert på
// heisens lokasjon og retning
void em_getNextFloor(int* em_nextFloor, int* em_queueUp, int* em_queueDown,
                     int* motorDirection, int* em_currentFloor) {
    // nextFloor er neste etasje
    // em_queueUp er køen oppover
    // em_queueDown er køen nedover
    // motorDir er retningen til motoren (må kun være 0 dersom køen er tom)
    //          den skal altså ikke være 0 fordi den står stille i en etasje og
    //          venter
    
    // Vil nå sjekke listene for å finne neste etasje
    // Tar nextFloor fra begge køene, dersom køene er tomme fra før
    if (*em_nextFloor == -1) {
        for (int i = 0; i < N_FLOORS; i++) {
            if (em_queueUp[i] != 0 || em_queueDown[i] != 0) {
                *em_nextFloor = i;
                return;
            }
        }
    }
    // Sjekker listene i samme retning som heisen kjører
    if ((*motorDirection == 1) && (*em_currentFloor != (N_FLOORS - 1))) {
        // Heisen er på vei oppover, og den er ikke i øverste etasje
        for (int i = *em_currentFloor + 1; i < N_FLOORS; i++) {
            // Itererer gjennom lista, fra etasjen over og te topp
            if (em_queueUp[i] != 0) {
                *em_nextFloor = i;
                return;
            }
        }
    } else if ((*motorDirection == -1) && (*em_currentFloor != 0)) {
        // Heisen er på vei nedover og den er ikke i siste etasje,
        // ekstrasjekken er for å ikke iterere utenfor arrayet,
        // kan det skape problemer? Pass på å bytte motorDir idet
        // den når topp og bunn-etasjen
        for (int i = *em_currentFloor - 1; i >= 0;
             i--) { // Itererer gjennom lista baklengs, fra etasjen under og te
                    // bunn
            if (em_queueDown[i] != 0) {
                *em_nextFloor = i;
                return;
            }
        }
    }

    // Hvis den ikke finner noe: sjekker listene i motsatt retning som heisen
    // kjører
    if (*motorDirection == 1) {
        for (int i = N_FLOORS - 1; i >= 0; i--) {
            // På vei oppover, vil hente fra øverste nedover-bestilling
            // og ta alle den retningen
            if (em_queueDown[i] != 0) {
                *em_nextFloor = i;
                return;
            }
        }
        for (int i = 0; i < N_FLOORS; i++) {
            // På vei oppover, vil hente fra øverste nedover-bestilling
            // og ta alle den retningen
            if (em_queueUp[i] != 0) {
                *em_nextFloor = i;
                return;
            }
        }
    } else if (*motorDirection == -1) {
        for (int i = 0; i < N_FLOORS; i++) {
            if (em_queueUp[i] != 0) {
                *em_nextFloor = i;
                return;
            }
        }
        for (int i = N_FLOORS - 1; i >= 0; i--) {
            if (em_queueDown[i] != 0) {
                *em_nextFloor = i;
                return;
            }
        }
    }

    // I teorien er det nå ingen bestillinger
    *em_nextFloor = -1;
};

// Printer køen og nextFloor til terminalen for enklere debugging
void em_printQueue(int* em_nextFloor, int* em_currentFloor, int* motorDirection, int* em_queueUp, int* em_queueDown) {
    printf("nF: %d   |   ", *em_nextFloor);
    printf("cF: %d   |   ", *em_currentFloor);
    printf("mD: %d   |   ", *motorDirection);

    printf("qUp: [");
    for (int i = 0; i < N_FLOORS - 1; i++) {
        printf("%d, ", em_queueUp[i]);
    }
    printf("%d]   |   ", em_queueUp[N_FLOORS - 1]);

    printf("qDown: [");
    for (int i = 0; i < N_FLOORS - 1; i++) {
        printf("%d, ", em_queueDown[i]);
    }
    printf("%d]\n", em_queueDown[N_FLOORS - 1]);
}