#include <Arduino.h>

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float64.h>

#include <Motors.h>

ros::NodeHandle nh;

//pins
const unsigned int pin_ENA = 6;
const unsigned int pin_ENB = 11;
const unsigned int pin_IN1 = 7;
const unsigned int pin_IN2 = 8;
const unsigned int pin_IN3 = 9;
const unsigned int pin_IN4 = 10;

//initialize motors
Motors motors(pin_ENA, pin_ENB, pin_IN1, pin_IN2, pin_IN3, pin_IN4);

void left_speed_callback(const std_msgs::Float64& cmd_msg){
  motors.setLeftSpeed(cmd_msg.data);
}
void right_speed_callback(const std_msgs::Float64& cmd_msg){
  motors.setRightSpeed(cmd_msg.data);
}

void left_direction_callback(const std_msgs::UInt16& cmd_msg){
  if(cmd_msg.data == 2){
    motors.setLeftToForward();
  }
  else if(cmd_msg.data == 1){
    motors.setLeftToReverse();
  }
  else if(cmd_msg.data == 0){
    motors.setLeftToBreak();
  }
}
void right_direction_callback(const std_msgs::UInt16& cmd_msg){
  if(cmd_msg.data == 2){
    motors.setRightToForward();
  }
  else if(cmd_msg.data == 1){
    motors.setRightToReverse();
  }
  else if(cmd_msg.data == 0){
    motors.setRightToBreak();
  }
}

ros::Subscriber<std_msgs::Float64> left_speed_subscriber("left_speed", left_speed_callback);
ros::Subscriber<std_msgs::Float64> right_speed_subscriber("right_speed", right_speed_callback);
ros::Subscriber<std_msgs::UInt16> left_direction_subscriber("left_direction", left_direction_callback);
ros::Subscriber<std_msgs::UInt16> right_direction_subscriber("right_direction", right_direction_callback);

void setup() {
  nh.initNode();
  nh.subscribe(left_speed_subscriber);
  nh.subscribe(right_speed_subscriber);
  nh.subscribe(left_direction_subscriber);
  nh.subscribe(right_direction_subscriber);
  motors.setLeftToForward();
  motors.setRightToForward();
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
}

void loop() {
  nh.spinOnce();
  delay(1);
}