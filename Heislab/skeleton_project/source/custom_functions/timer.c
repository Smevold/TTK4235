#include "timer.h"
#include <sys/time.h>
// #include <stdio.h>

static double get_wall_time(void){
    struct timeval time;
    gettimeofday(&time, NULL);
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

void timer_start(clock_t* pt_start,clock_t* pt_end){
    *pt_start = get_wall_time();
    *pt_end = *pt_start + 3;
}

int timer_isTimeOut(clock_t *pt_start,clock_t *pt_end){
    *pt_start = get_wall_time();
    if (*pt_end <= *pt_start){
        return 1;
    }
    return 0;
}