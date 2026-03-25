#include "hal.h"
#include "display.h"
#include <stdio.h>

int main(void) {
    hal_display_init();
    hal_gpio_init(5, false);

    uint32_t last = 0;

    while (1) {
        uint32_t now = hal_time_ms();

        if (now - last >= 33) {
            last = now;
            uint8_t start = 64;

            display_clear();

            if(hal_gpio_get(5)) {
                draw_string(0,  0, "The key system works!");
            } else {
                draw_string(0, 0, "Hello World!");
            }
           
            hal_display_flush();
        }
    }

    return 0;
}