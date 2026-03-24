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

            display_clear();

            if(!hal_gpio_get(5)) {
                printf("KEY PRESSED\n");
                draw_string(0, 0, "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$\%^&*()");
            } else {
                draw_string(0, 0, "abcdefghijklmnopqrstuvwxyz1234567890");
            }

            hal_display_flush();
        }
    }

    return 0;
}