#include "gpiote.h"

void gpiote_init() {
    // Leser av knappen
    GPIOTE->CONFIG[0] = (1 << 0) + (13 << 8) + (1 << 16);
    
    // Setter LED-ene
    for (int i = 1; i <= 4; i++) {
        GPIOTE->CONFIG[i] = (3 << 0) + ((16 + i) << 8) + (3 << 16) + (0 << 20);
    }
}