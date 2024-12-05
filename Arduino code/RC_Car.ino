#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Motor control pins
const int motorA_pin1 = 16; // Motor A forward
const int motorA_pin2 = 4;  // Motor A backward
const int motorB_pin1 = 18; // Motor B forward
const int motorB_pin2 = 17; // Motor B backward

// #define MAX_MOTOR_SPEED 255

void turnLeft(int speed) {
    analogWrite(motorA_pin1, 0);
    analogWrite(motorA_pin2, speed);
    analogWrite(motorB_pin1, speed);
    analogWrite(motorB_pin2, 0);
}

void turnRight(int speed) {
    analogWrite(motorA_pin1, speed);
    analogWrite(motorA_pin2, 0);
    analogWrite(motorB_pin1, 0);
    analogWrite(motorB_pin2, speed);
}

void moveForward(int speed) {
    analogWrite(motorA_pin1, speed);
    analogWrite(motorA_pin2, 0);
    analogWrite(motorB_pin1, speed);
    analogWrite(motorB_pin2, 0);
}

void moveBackward(int speed) {
    analogWrite(motorA_pin1, 0);
    analogWrite(motorA_pin2, speed);
    analogWrite(motorB_pin1, 0);
    analogWrite(motorB_pin2, speed);
}

void stopMotors() {
    analogWrite(motorA_pin1, 0);
    analogWrite(motorA_pin2, 0);
    analogWrite(motorB_pin1, 0);
    analogWrite(motorB_pin2, 0);
}


void setup()
{
  pinMode(motorA_pin1, OUTPUT);
  pinMode(motorA_pin2, OUTPUT);
  pinMode(motorB_pin1, OUTPUT);
  pinMode(motorB_pin2, OUTPUT);

  Dabble.begin("MyBluetoothCar"); 
}

void loop()
{

  Dabble.processInput();

  if (GamePad.isUpPressed())
  {
    moveForward(120);
    delay(200);
    stopMotors();
  }

  else if (GamePad.isDownPressed())
  {
    moveBackward(100);
    delay(200);
    stopMotors();
  }

  else if (GamePad.isLeftPressed())
  {
    turnLeft(100);
    delay(100);
    stopMotors();
  }

  else if (GamePad.isRightPressed())
  {
    turnRight(120);
    delay(100);
    stopMotors();
  }
  

}