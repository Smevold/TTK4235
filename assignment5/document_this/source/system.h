#ifndef SYSTEM_H
#define SYSTEM_H

/**
 * @file
 * @brief Definition for created types
 */

/**
 * @brief Enum of tuning rules
 */
typedef enum {
    Classic_Ziegler_Nichols, /*< Ziegler Nichols */
    Pessen_Integral_Rule /*< Pessen */
} Tuning;

/**
 * @brief A structure to represent a system and desired PID tuning method.
 */
typedef struct {
    double Ku;            /** < The gain margin for loop stability */
    double Tu;            /** < The period of the oscillations frequency at the stability limit */
    Tuning tuning_method; /** < The desired PID tuning method */
} System;


/**
* @brief Creates a new pointer with type System
*
* @param[in] Ku The value of the systems open loop gain
* @param[in] Tu The value of the systems open loop time-constant
*/
System * system_create(double Ku, double Tu, Tuning tuning_method);

/**
* @brief Frees up memory and deletes the values of the current system
*
* @param[in] system_current The system that gets deleted and memory freed
*/
void system_delete(System * system_current);

#endif
