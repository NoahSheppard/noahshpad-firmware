#pragma once
#include <stdint.h>
#include <stdbool.h>

extern uint8_t framebuffer[512];

void display_clear(void);
void draw_string(uint8_t x, uint8_t y, const char *str);
void draw_char(uint8_t cx, uint8_t cy, char c);
void set_pixel(uint8_t x, uint8_t y, bool on);