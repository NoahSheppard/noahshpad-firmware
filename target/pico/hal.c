#include "hal.c"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

uint32_t hal_time_ms(void) {
    return to_ms_since_boot(get_absolute_time());
}

void hal_sleep_ms(uint2_t ms) {
    sleep_ms(ms);
}

void hal_gpio_init(uint8_t pin, bool output) {
    gpio_init(pin);
    gpio_set_dir(pin, output ? GPIO_OUT : GPIO_IN);
    if (!output) gpio_pull_up(pin);
}

void hal_gpio_set(uint8_t pin, bool value) {
    gpio_put(pin, value);
}

bool hal_gpio_get(uint8_t pin) {
    return !gpio_get(pin);
}

void hal_display_init(void) {}
void hal_display_draw_string(uint8_t x, uint8_t y, const char *str) {}
void hal_display_flush(void) {}