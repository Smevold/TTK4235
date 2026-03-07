#pragma once
#include <stdio.h>
#include "../driver/elevio.h"

/**
* @file
* @brief Denne skal følge med på knappene og bruke en algoritme til å finne ut hvilken etasje som er den neste
*/

/**
* @brief Sjekker hvilke knakker som blir trykket
* @param[out] f Hvilken etasje som har blitt trykket på, der @p f er nullindeksert
*
* @warning Dersom @p f er lik -1, skal dette telle som at ingen etasjeknapp er trykket på
*/
int ioTest_getNextFloor();

/**
* @brief Sjekker hvilken etasje heisen er i
*/
int ioTest_getCurrentFloor();