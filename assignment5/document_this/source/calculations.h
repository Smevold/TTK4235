#ifndef CALCULATIONS_H
#define CALCUATIONS_H
#include "system.h"

/**
* @file
* @brief Creates parameters for PID-Tuner
*/

/**
* @brief Calculates the value of P by using the method defined in main.
*
* @param[in] current_system Values for the open loop system
*
* @return Value of @c P_parameter based on method used
*/
double calculate_P_parameter(System * current_system);

/**
* @brief Calculates the value of I by using the method defined in main.
*
* @param[in] current_system Values for the open loop system
*
* @return Value of @c I_parameter based on method used
*/
double calculate_I_parameter(System * current_system);

/**
* @brief Calculates the value of D by using the method defined in main.
*
* @param[in] current_system Values for the open loop system
*
* @return Value of @c D_parameter based on method used
*/
double calculate_D_parameter(System * current_system);

#endif
