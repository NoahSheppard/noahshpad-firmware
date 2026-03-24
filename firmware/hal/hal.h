#pragma once
#include <stdint.h>
#include <stdbool.h>

uint32_t hal_time_ms(void);
void hal_sleep_ms(uint32_t ms);

void hal_gpio_init(uint8_t pin, bool output);
void hal_gpio_set(uint8_t pin, bool value);
bool hal_gpio_get(uint8_t pin);

void hal_display_init(void);
void hal_display_flush(void);