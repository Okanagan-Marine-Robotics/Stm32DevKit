#include <Arduino.h>
#include "testsensor.h"  // Include the header file for the ultrasonic sensor

void setup() {
    Serial.begin(115200);  // Start serial communication
    initUltrasonic();      // Initialize ultrasonic sensor
}

void loop() {
    float distance = readUltrasonicDistance();  // Get the distance from the ultrasonic sensor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(2000);  // Delay between readings
}
