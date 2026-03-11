#pragma once

#include "../driver/elevio.h"
#include <stdio.h>

void mDirUp(int *MotorDirection);
void mDirDown(int *MotorDirection);
void mDirStop(int *MotorDirection);

/**
* @brief Skrur av alle bestillingslysene i gjeldende etasje
* @param[in] Pass-by-reference: gjeldende etasje
*/
void lights_floorOffCurrent(int* em_currentFloor);

/**
* @brief Skrur av alle bestillingslysene i alle etasjer
*/
void lights_floorOffAll();