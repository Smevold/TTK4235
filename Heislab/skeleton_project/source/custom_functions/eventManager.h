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
* @brief Sjekker hvilken etasje heisen er i. Nullindeksert
* @param[out]
*  @warning Dersom heisen er mellom etasjer, vil den returnere -1
*/
int em_getCurrentFloor();

/**
* @brief Genererer etasjerekkefølge basert på 
*/
int em_getNextFloor();