#pragma once
#include <stdio.h>
#include "../driver/elevio.h"

/**
* @file
* @brief Denne skal følge med på knappene og bruke en algoritme til å finne ut hvilken etasje som er den neste
*/

/**
* @brief Sletter hele kø-en til Event Manageren
* @param[in] em_queue Peker til køen som programmet bruker til å finne neste etasje
*/
void em_clear(int* em_queueUp, int* em_queueDown);

/**
* @brief Sjekker hvilke knakker som blir trykket
* @param[in] f Pass-by-reference: Hvilken etasje som har blitt trykket på, @p f er nullindeksert
* @param[in] b Pass-by-reference: Hvilken retning som har blitt trykket på, 0 = opp, 1 = ned, 2 = fra kabinen
*
* @warning Dersom @p f er lik -1, skal dette telle som at ingen etasjeknapp er trykket på
*/
void em_checkBtnPressed(int* floor, int* btn);

/**
* @brief Sjekker hvilken etasje heisen er i, og endrer kanskje currentFloor. Nullindeksert
* @param[in] currentFloor currentFloor er en peker til forrige etasje den detekterte
*
* @warning Dersom heisen er mellom etasjer, vil den ikke oppdatere verdien
*/
void em_getCurrentFloor(int* em_currentFloor);

/**
* @brief Fjerner currentFloor fra heiskøen i begge retninger. currentFloor trenger ikke oppdateres før denne funksjonen kalles.
* @param[in] currentFloor Pass-by-reference: Holder styr på gjeldene etasje
* @param[in] em_queueUp Pass-by-reference: Heiskøen i oppover-retning
* @param[in] em_queueDown Pass-by-reference: Heiskøen i nedover-retning
*/
void em_clearCurrentFloor(int* em_currentFloor, int* em_queueUp, int* em_queueDown);

/**
* 
*/
void em_updateQueues(int* em_queueUp, int* em_queueDown);

/**
* @brief Genererer etasjerekkefølge basert på 
* @param[in] nextFloor nextFloor er en peker til forrige etasje heisen var på vei til
*/
void em_getNextFloor(int *em_nextFloor, int* em_queueUp, int* em_queueDown, int* motorDirection, int* em_currentFloor);

/**
* @brief Skriver kø og nextFloor til terminalen for debugging
*/
void em_printQueue(int* em_nextFloor, int* em_queueUp, int* em_queueDown);