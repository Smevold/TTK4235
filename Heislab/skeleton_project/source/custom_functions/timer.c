#include "timer.h"
#include <time.h>
#include <stdio.h>

void timer_start(clock_t* pt_start,clock_t* pt_end){
    *pt_start = clock();
    *pt_end = *pt_start + 3000;
}

int timer_isTimeOut(clock_t *pt_start,clock_t *pt_end){
    *pt_start = clock();
    if (*pt_end >= *pt_start){
        return 1;
    }
    return 0;
}