#pragma once
#include <stdint.h> 
int setupMotor();

int setupMotor2();
void rotateMotor2(int steps, bool isFast, bool clockwise);

typedef uint8_t (*StepSequence)[4]; 

void rotateMotor(int steps,bool isFast, bool clockwise);