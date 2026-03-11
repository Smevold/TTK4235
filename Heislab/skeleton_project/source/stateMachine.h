#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "custom_functions/timer.h"
#include "driver/elevio.h"
#include "custom_functions/eventManager.h"
#include "custom_functions/smallerFunctions.h"

/**
 * @file
 * @brief Dette er selve tilstandsmaskinen i heisen, den skal aktivt endre tilstand ut ifra hva som skjer.
 */

/**
 * @brief Dette er tilstanden som skjer ved oppstart av programmet.
 */
void state_startUp();

/**
 * @brief Dette er tilstanden hvor heisen er stasjonær i en etasje med døren lukket.
 * @param[in] em_queue er en pointer til et array med de neste etasjene 
 * som eventManager bestemmer hva skal være, brukes til pass-by-reference
 * @param[in] em_nextFloor er en pointer til neste etasje som heisen skal gå til
 * @param[in] em_currentFloor er en pointer til etasjen heisen er i
 * @param[out] f brukes for å stoppe heisen der den er dersom den er 1.
 */
int state_stationary(int *em_queueUp, int *em_queueDown, int *em_nextFloor, int *em_currentFloor, int *motorDirection);

/**
 * @brief Dette er tilstanden hvor heisen er i bevegelse.
 * @param[in] em_queue er en pointer til et array med de neste etasjene 
 * som eventManager bestemmer hva skal være, brukes til pass-by-reference
 * @param[in] em_nextFloor er en pointer til neste etasje som heisen skal gå til
 * @param[in] em_currentFloor er en pointer til etasjen heisen er i
 * @param[out] f brukes for å stoppe heisen der den er dersom den er 1.
 */
int state_move(int *em_queueUp, int *em_queueDown, int *em_nextFloor, int *em_currentFloor, int *motorDirection);

/**
 * @brief Dette er tilstanden hvor heisen er stasjonær i en etasje med døren åpmet.
 * @param[in] em_queue er en pointer til et array med de neste etasjene 
 * som eventManager bestemmer hva skal være, brukes til pass-by-reference
 * @param[in] em_nextFloor er en pointer til neste etasje som heisen skal gå til
 * @param[in] em_currentFloor er en pointer til etasjen heisen er i
 * @param[out] f brukes for å stoppe heisen der den er dersom den er 1.
 */
int state_openDoor(int *em_queueUp, int *em_queueDown, int *em_nextFloor, int *em_currentFloor, int *motorDirection);