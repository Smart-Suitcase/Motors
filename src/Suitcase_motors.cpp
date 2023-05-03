#include "Suitcase_motors.h"

Motors::Motors(uint8_t pin_ENA, uint8_t pin_ENB, uint8_t pin_IN1, uint8_t pin_IN2, uint8_t pin_IN3, uint8_t pin_IN4) {
    _pin_ENA = pin_ENA;
    _pin_ENB = pin_ENB;
    _pin_IN1 = pin_IN1;
    _pin_IN2 = pin_IN2;
    _pin_IN3 = pin_IN3;
    _pin_IN4 = pin_IN4;
    _left_speed = 0;
    _right_speed = 0;
    _left_direction = BREAK;
    _right_direction = BREAK;

    pinMode(_pin_ENA, OUTPUT);
    pinMode(_pin_ENB, OUTPUT);
    pinMode(_pin_IN1, OUTPUT);
    pinMode(_pin_IN2, OUTPUT);
    pinMode(_pin_IN3, OUTPUT);
    pinMode(_pin_IN4, OUTPUT);
}

void Motors::setLeftSpeed(unsigned short pwm_value) {
    _left_speed = pwm_value;
    analogWrite(_pin_ENA, _left_speed);
}

void Motors::setRightSpeed(unsigned short pwm_value) {
    _right_speed = pwm_value;
    analogWrite(_pin_ENB, _right_speed);
}

unsigned short Motors::getLeftSpeed() {
    return (_left_direction != BREAK) ? _left_speed : 0;
}

unsigned short Motors::getRightSpeed() {
    return (_left_direction != BREAK) ? _left_speed : 0;
}

void Motors::setLeftToForward() {
  digitalWrite(_pin_IN1, HIGH);
  digitalWrite(_pin_IN2, LOW);

  _left_direction = FORWARD;
}

void Motors::setRightToForward() {
  digitalWrite(_pin_IN3, HIGH);
  digitalWrite(_pin_IN4, LOW);

  _right_direction = FORWARD;
}

void Motors::setLeftToReverse() {
  digitalWrite(_pin_IN1, LOW);
  digitalWrite(_pin_IN2, HIGH);

  _left_direction = BACKWARD;
}

void Motors::setRightToReverse() {
  digitalWrite(_pin_IN3, LOW);
  digitalWrite(_pin_IN4, HIGH);

  _right_direction = BACKWARD;
}

void Motors::setLeftToBreak() {
  digitalWrite(_pin_IN1, LOW);
  digitalWrite(_pin_IN2, LOW);

  _left_direction = BREAK;
}

void Motors::setRightToBreak() {
  digitalWrite(_pin_IN3, LOW);
  digitalWrite(_pin_IN4, LOW);

  _right_direction = BREAK;
}

Motors::Direction Motors::getLeftDirection() {
    return _left_direction;
}

Motors::Direction Motors::getRightDirection() {
    return _right_direction;
}