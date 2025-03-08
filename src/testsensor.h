#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

#define TRIG_PIN PB4  // Digital Output
#define ECHO_PIN PB2  // Digital Input

// Function declarations
void initUltrasonic();
void sendTriggerPulse();
long measureEchoDuration();
float calculateDistance(long duration);
float readUltrasonicDistance();

#endif
