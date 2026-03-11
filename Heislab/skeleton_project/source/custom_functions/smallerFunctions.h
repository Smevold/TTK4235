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