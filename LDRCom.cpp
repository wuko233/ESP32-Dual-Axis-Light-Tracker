#include <Arduino.h>
#include "config.h"

int setupLDR() {
    analogReadResolution(12);
    pinMode(LDR_IN1, INPUT);
    pinMode(LDR_IN2, INPUT);
    pinMode(LDR_IN3, INPUT);
    pinMode(LDR_IN4, INPUT);
    return 200;
}