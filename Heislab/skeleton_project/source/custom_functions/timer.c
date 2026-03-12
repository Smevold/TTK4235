#include "timer.h"
#include <sys/time.h>
// #include <stdio.h>

static double timer_getTime(void){
    struct timeval time;
    gettimeofday(&time, NULL);
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

void timer_start(clock_t* pt_start,clock_t* pt_end){
    *pt_start = timer_getTime();
    *pt_end = *pt_start + 3;
}

int timer_isTimeOut(clock_t *pt_start,clock_t *pt_end){
    *pt_start = timer_getTime();
    if (*pt_end <= *pt_start){
        return 1;
    }
    return 0;
}