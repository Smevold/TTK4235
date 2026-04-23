#include "ppi.h"
#include <stdint.h>

void channel_init() {
    // Enable 5 registers
    for (int i = 0; i <= 4; i++) {
        PPI->CHENSET = (1 << i);
    }

    for (int i = 0; i <= 3; i++) {
        PPI->PPI_CH[i].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
        PPI->PPI_CH[i].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[i + 1]);
    }
}