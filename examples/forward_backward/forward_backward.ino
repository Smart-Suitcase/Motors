#include <Motors.h>

//pins
const unsigned int pin_ENA = 3;
const unsigned int pin_ENB = 7;
const unsigned int pin_IN1 = 5;
const unsigned int pin_IN2 = 6;
const unsigned int pin_IN3 = 7;
const unsigned int pin_IN4 = 8;

//initialize motors
Motors motors(pin_ENA, pin_ENB, pin_IN1, pin_IN2, pin_IN3, pin_IN4);

void setup()
{
    motors.setLeftSpeed(100);
    motors.setRightSpeed(100);
}

void loop()
{
    motors.setLeftToForward();
    motors.setRightToForward();

    delay(3000);

    motors.setLeftToBreak();
    motors.setRightToBreak();

    delay(3000);

    motors.setLeftToReverse();
    motors.setRightToReverse();

    delay(3000);

    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);

    delay(3000);

    motors.setLeftSpeed(100);
    motors.setRightSpeed(100);
}