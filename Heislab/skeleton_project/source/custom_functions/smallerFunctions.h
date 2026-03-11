#pragma once

#include "../driver/elevio.h"
#include <stdio.h>

/**
 * @file
 * @brief Samling av alle de mindre funksjonene som er lettere å definere seperat.
 */


/**
 * @brief Funksjon for å sette motorretning oppover 
 */
void mDirUp(int *MotorDirection);

/**
 * @brief Funksjon for å sette motorretning nedover 
 */
void mDirDown(int *MotorDirection);

/**
 * @brief Funksjon for å stoppe heisen 
 */
void mDirStop(int *MotorDirection);

/**
* @brief Skrur av alle bestillingslysene i gjeldende etasje
* @param[in] em_currentFloor Pass-by-reference: gjeldende etasje
*/
void lights_floorOffCurrent(int* em_currentFloor);

/**
* @brief Skrur av alle bestillingslysene i alle etasjer
*/
void lights_floorOffAll();