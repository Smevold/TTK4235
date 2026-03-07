#pragma once
#include <time.h>

void timer_start(time_t *pt_start,time_t *pt_end);
int timer_isTimeOut(time_t *pt_start,time_t *pt_end);

