#include <Arduino.h>

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>

#include <Motors.h>

#include <NewPing.h>

ros::NodeHandle nh;

//pins
const unsigned int pin_ENA = 6;
const unsigned int pin_ENB = 11;
const unsigned int pin_IN1 = 7;
const unsigned int pin_IN2 = 8;
const unsigned int pin_IN3 = 9;
const unsigned int pin_IN4 = 10;

#define TRIGGER_PIN  4
#define ECHO_PIN     5
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
std_msgs::String mode_msg;
int low_anti_bounce = 5;
int high_anti_bounce = 5;
int cycle_divide = 100;  // Wait 50ms between pings (recommended by NewPing library)

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
ros::Publisher mode_publisher("mode", &mode_msg);

void setup() {
  nh.initNode();
  nh.subscribe(left_speed_subscriber);
  nh.subscribe(right_speed_subscriber);
  nh.subscribe(left_direction_subscriber);
  nh.subscribe(right_direction_subscriber);
  nh.advertise(mode_publisher);
  motors.setLeftToForward();
  motors.setRightToForward();
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
}

void loop() {
  cycle_divide = cycle_divide - 1;
  if (cycle_divide == 0){
    int dist = sonar.ping_cm();
    if (dist < 12 && dist != 0){
      high_anti_bounce = 5;
      low_anti_bounce = low_anti_bounce - 1;
    }
    else {
      low_anti_bounce = 5;
      high_anti_bounce = high_anti_bounce - 1;
    }
    if (low_anti_bounce == 0){
      mode_msg.data = "off";
      mode_publisher.publish(&mode_msg);
    }
    else if (high_anti_bounce == 0){
      mode_msg.data = "auto";
      mode_publisher.publish(&mode_msg);
    }
    cycle_divide = 75;
  }
  nh.spinOnce();
  delay(1);
}