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

            // Key Matrix

            if (hal_gpio_get(10) && hal_gpio_get(4)) {
                draw_string(0, 0, "Key 1 Pressed");
            }
            else if (hal_gpio_get(10) && hal_gpio_get(5)) {
                draw_string(0, 0, "Key 2 Pressed");
            }
            else if (hal_gpio_get(10) && hal_gpio_get(6)) {
                draw_string(0, 0, "Key 3 Pressed");
            }
            else if (hal_gpio_get(10) && hal_gpio_get(7)) {
                draw_string(0, 0, "Key 4 Pressed");
            }
            else if (hal_gpio_get(11) && hal_gpio_get(4)) {
                draw_string(0, 0, "Key 5 Pressed");
            }
            else if (hal_gpio_get(11) && hal_gpio_get(5)) {
                draw_string(0, 0, "Key 6 Pressed");
            }
            else if (hal_gpio_get(11) && hal_gpio_get(6)) {
                draw_string(0, 0, "Key 7 Pressed");
            }
            else if (hal_gpio_get(11) && hal_gpio_get(7)) {
                draw_string(0, 0, "Key 8 Pressed");
            } else {
                draw_string(0, 0, "No Key Pressed");
            }
           
            hal_display_flush();
        }
    }

    return 0;
}