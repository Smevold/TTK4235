#include "uart.h"
#include "gpio.h"
#include <stdio.h>
#include <sys/types.h> // For ssize_t

ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }

    return count;
}

ssize_t _read(int fd, void *buf, size_t count){
    char *str = (char *)(buf);
    char letter;
    
    do {
        letter = uart_read();
    } while(letter == '\0');
    
    *str = letter;
    
    return 1;
}

int main() {
    button_init();
    led_init();
    uart_init();

    int sleep = 0;
    int led = 0;
    int firstNumber = 0;
    int secondNumber = 0;
    while(1){
        // Knapp 1
        if (!(GPIO->IN & (1 << 13))) {
            uart_send('A');
        }
        // Knapp 2
        if (!(GPIO->IN & (1 << 14))) {
            uart_send('B');
        }

        // Knapp 3
        if (!(GPIO->IN & (1 << 15))) {
            iprintf("The average grade in TTK%d was in %d was: B\n\r", 4235, 2022);
        }

        // Knapp 4
        if (!(GPIO->IN & (1 << 16))) {
            iprintf("Write first number: \n\r");
            while (!(firstNumber)) {
                scanf("%d", &firstNumber);
            }
            
            iprintf("Write second number: \n\r");
            while(!(secondNumber)) {
                scanf("%d", &secondNumber);
            }

            iprintf("Result: %d\n\r", firstNumber*secondNumber);
            firstNumber = secondNumber = 0;
        }

        if (uart_read() != '\0') {
            if (led) {
                for(int i = 17; i <= 20; i++){
				    GPIO->OUTCLR = (1 << i);
			    }
                led = 0;
            } else {
                for(int i = 17; i <= 20; i++){
				    GPIO->OUTSET = (1 << i);
			    }
                led = 1;
            }
        }

        sleep = 10000;
        while(--sleep);
    }

    return 0;
}