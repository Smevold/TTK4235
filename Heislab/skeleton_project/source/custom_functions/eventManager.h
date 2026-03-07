#pragma once
#include <stdio.h>
#include "../driver/elevio.h"

/**
* @file
* @brief Denne skal følge med på knappene og bruke en algoritme til å finne ut hvilken etasje som er den neste
*/

/**
* @brief Sjekker hvilke knakker som blir trykket
* @param[out] f Hvilken etasje som har blitt trykket på, @p f er nullindeksert
*
* @warning Dersom @p f er lik -1, skal dette telle som at ingen etasjeknapp er trykket på
*/
int em_checkBtnPressed();

/**
* @brief Sjekker hvilken etasje heisen er i, og endrer kanskje currentFloor. Nullindeksert
* @param[in] currentFloor currentFloor er en peker til forrige etasje den detekterte
*
* @warning Dersom heisen er mellom etasjer, vil den ikke oppdatere verdien
*/
void em_getCurrentFloor(int *currentFloor);

/**
* @brief Genererer etasjerekkefølge basert på 
* @param[in] nextFloor nextFloor er en peker til forrige etasje heisen var på vei til
*/
void em_getNextFloor(int *nextFloor);