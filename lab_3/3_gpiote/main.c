#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main() {
    button_init();
    led_init();

    gpiote_init();
    channel_init();

    while(1);

    return 0;
}