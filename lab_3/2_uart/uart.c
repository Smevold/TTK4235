#include "uart.h"
#include "gpio.h"
#include <stdint.h>

#define UART ((NRF_UART_REG*)+0x40002000)

typedef struct {
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t TASKS_STOPRX;
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t TASKS_STOPTX;
    volatile uint32_t RESERVED1[(0x01C-0x00C-4)/4];
    volatile uint32_t TASKS_SUSPEND;
    volatile uint32_t RESERVED2[(0x100-0x01C-4)/4];
    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
    volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t RESERVED3[(0x11C-0x108-4)/4];
    volatile uint32_t EVENTS_TXDRDY;
    volatile uint32_t RESERVED4[(0x124-0x11C-4)/4];
    volatile uint32_t EVENTS_ERROR;
    volatile uint32_t RESERVED5[(0x144-0x124-4)/4];
    volatile uint32_t EVENTS_RXTO;
    volatile uint32_t RESERVED7[(0x200-0x144-4)/4];
    volatile uint32_t SHORTS;
    volatile uint32_t RESERVED8[(0x304-0x200-4)/4];
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RESERVED9[(0x480-0x308-4)/4];
    volatile uint32_t ERRORSRC;
    volatile uint32_t RESERVED10[(0x500-0x480-4)/4];
    volatile uint32_t ENABLE;
    volatile uint32_t RESERVED11;
    volatile uint32_t PSELRTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVED12[(0x524-0x51C-4)/4];
    volatile uint32_t BAUDRATE;
} NRF_UART_REG;

void uart_init() {

    // Pin 6 is TXD (Output)
    GPIO->DIRSET = (1 << 6);
    GPIO->OUTCLR = (1 << 6);

    // Pin 8 is RXD (Input)
    GPIO->DIRCLR = (1 << 8);
    GPIO->PIN_CNF[8] = (3 << 2);

    // Selecting what pin UART should use
    UART->PSELTXD = (6 << 0) + (0 << 31);
    UART->PSELRXD = (8 << 0) + (0 << 31);

    // Disable RTS and CTS
    UART->PSELRTS = (1 << 31);
    UART->PSELCTS = (1 << 31);

    // Select Baudrate to 9600
    UART->BAUDRATE = 0x00275000;

    // Enable UART
    UART->ENABLE = 8;

    // Start RX
    UART->TASKS_STARTRX = 1;
};

void uart_send(char letter) {
    UART->TASKS_STARTTX = 1;

    UART->TXD = letter;
   
    while (!(UART->EVENTS_TXDRDY));
    UART->EVENTS_TXDRDY = 0;

    UART->TASKS_STOPTX = 1;
}

char uart_read() {
    if (UART->EVENTS_RXDRDY) {
        UART->EVENTS_RXDRDY = 0;
        return UART->RXD;
    } else {
        return '\0';
    }
}