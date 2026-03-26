#pragma once
#include <time.h>

/**
 * @file
 * @brief Timeren, den kan startes og sjekkes om er ferdig
 */


/**
 * @brief Start en timer på 3 sekunder 
 */
void timer_start(time_t *pt_start,time_t *pt_end);

/**
 * @brief Sjekk om 3 sekunder har gått 
 */
int timer_isTimeOut(time_t *pt_start,time_t *pt_end);

