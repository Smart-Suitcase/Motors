#include <Suitcase_motors.h>

//pins
const unsigned int pin_ENA = 6;
const unsigned int pin_ENB = 11;
const unsigned int pin_IN1 = 7;
const unsigned int pin_IN2 = 8;
const unsigned int pin_IN3 = 9;
const unsigned int pin_IN4 = 10;

//initialize motors
Motors motors(pin_ENA, pin_ENB, pin_IN1, pin_IN2, pin_IN3, pin_IN4);

void setup()
{
    motors.setLeftSpeed(150);
    motors.setRightSpeed(150);
    motors.setLeftToForward();
    motors.setRightToForward();
}

void loop()
{
    
}