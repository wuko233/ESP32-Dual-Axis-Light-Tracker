#pragma once
#include <U8g2lib.h>
#include <Arduino.h>
#include <string.h>

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED;

int setupDisplay();

void display(const char* info, int display_time);