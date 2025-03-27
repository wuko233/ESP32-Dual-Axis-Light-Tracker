#include <Arduino.h>

#include "LDRCom.h"
#include "motor.h"
#include "oled_display.h"
#include "config.h"

#define MOTOR_STEP 50

#define BOTTOM_LDR_1 LDR_IN1
#define BOTTOM_LDR_2 LDR_IN2
#define TOP_LDR_1 LDR_IN3
#define TOP_LDR_2 LDR_IN4

#define LDR_DIFF 500

struct MotorControl {
    int ldrPin1;
    int ldrPin2;
    bool isFast;
    void (*rotate)(int, bool, bool);
    String motorName;
};

MotorControl motor1 = {
    BOTTOM_LDR_1, BOTTOM_LDR_2, 
    false,
    rotateMotor,
    "Motor1"
};

MotorControl motor2 = {
    TOP_LDR_1, TOP_LDR_2, 
    false,
    rotateMotor2,
    "Motor2"
};

void setup() {
    Serial.begin(115200);
    setupDisplay();
    bool ldrStatus = (setupLDR() == 200);
    bool motorStatus = (setupMotor() == 200);
    bool motor2Status = (setupMotor2() == 200);
    String result = "[1] LDR: " + String(ldrStatus ? "OK" : "FAIL") + 
         "\n[2] M1: " + String(motorStatus ? "OK" : "FAIL") +
         "\n[3] M2: " + String(motor2Status ? "OK" : "FAIL");
    display(result.c_str(), 1500);
}

void controlMotor(MotorControl &motor) {
    int val1 = analogRead(motor.ldrPin1);
    int val2 = analogRead(motor.ldrPin2);
    int diff = abs(val1 - val2);
    String info = motor.motorName + ":";
    info += "\nL1=" + String(val1);
    info += " L2=" + String(val2);
    info += "\nDiff=" + String(diff);

    if (diff >= LDR_DIFF) {
        bool direction = val1 < val2; 
        motor.rotate(MOTOR_STEP, motor.isFast, direction);
        info += direction ? "\n->Right" : "\n<-Left";
    } else {
        info += "\nBalanced";
    }
    
    display(info.c_str(), 0);
}

void loop() {
    controlMotor(motor1);
    delay(200);
    
    controlMotor(motor2);
    delay(200);
}
