#include "smallerFunctions.h"

void mDirUp(int *MotorDirection){
    elevio_motorDirection(DIRN_UP);
    *MotorDirection = 1;
}
void mDirDown(int *MotorDirection){
    elevio_motorDirection(DIRN_DOWN);
    *MotorDirection = -1;
}
void mDirStop(int *MotorDirection){
    elevio_motorDirection(DIRN_STOP);
}

