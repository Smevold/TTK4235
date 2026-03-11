#pragma once
#include <stdio.h>
#include "../driver/elevio.h"

/**
* @file
* @brief Funksjoner for å skru av og på spesifikke lys
*/

/**
* @brief Skrur av alle bestillingslysene i gjeldende etasje
* @param[in] Pass-by-reference: gjeldende etasje
*/
void lights_floorOffCurrent(int* em_currentFloor);

/**
* @brief Skrur av alle bestillingslysene i alle etasjer
*/
void lights_floorOffAll();