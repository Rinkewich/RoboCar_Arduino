/*
Library for the ultrasonic distance sensor HC-SR04
Developer: Maksim Masalski
E-mail: maxxliferobot@gmail.com
*/

#include <Arduino.h>
#include "HCSR04RobotCar.h"
long duration;
int distance;
int trigPin = 7;
int echoPin = 6;
void Ultrasonic::attach()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
int Ultrasonic::read() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}
