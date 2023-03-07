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
    motors.setLeftSpeed(50);
    motors.setRightSpeed(50);
}

void loop()
{
    motors.setLeftToForward();
    motors.setRightToForward();

    delay(300);

    motors.setLeftSpeed(100);
    motors.setRightSpeed(100);

    delay(300);

    motors.setLeftSpeed(150);
    motors.setRightSpeed(150);

    delay(300);

    motors.setLeftSpeed(200);
    motors.setRightSpeed(200);

    delay(3000);

    motors.setLeftToBreak();
    motors.setRightToBreak();

    delay(700);

    motors.setLeftToReverse();
    motors.setRightToReverse();

    delay(3000);

    motors.setLeftSpeed(0);

    delay(1000);

    motors.setLeftSpeed(200);
    motors.setRightSpeed(0);

    delay(1500);

    motors.setRightToForward();
    motors.setRightSpeed(200);

    delay(1500);

    motors.setRightToReverse();

    delay(2000);

    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);

    delay(1000);
}