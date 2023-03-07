#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

class Motors
{
public:
    typedef enum
    {
        FORWARD = 0,
        BACKWARD = 1,
        BREAK = -1
    } Direction;

    Motors(uint8_t pin_ENA, uint8_t pin_ENB, uint8_t pin_IN1, uint8_t pin_IN2, uint8_t pin_IN3, uint8_t pin_IN4);

    void setLeftSpeed(unsigned short pwm_value);
    void setRightSpeed(unsigned short pwm_value);
    unsigned short getLeftSpeed();
    unsigned short getRightSpeed();
    void setLeftToForward();
    void setRightToForward();
    void setLeftToReverse();
    void setRightToReverse();
    void setLeftToBreak();
    void setRightToBreak();
    Direction getLeftDirection();
    Direction getRightDirection();

private:
    byte _pin_ENA;
    byte _pin_ENB;
    byte _pin_IN1;
    byte _pin_IN2;
    byte _pin_IN3;
    byte _pin_IN4;
    byte _left_speed;
    byte _right_speed;
    Motors::Direction _left_direction;
    Motors::Direction _right_direction;
};

#endif