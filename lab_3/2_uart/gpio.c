#include "gpio.h"

void button_init() { 
	for (int i = 13; i <= 16; i++){
		GPIO->DIRCLR = (1 << i);
		GPIO->PIN_CNF[i] = (3 << 2);
	}
}

void led_init() {
    // Configure LED Matrix
	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}
}