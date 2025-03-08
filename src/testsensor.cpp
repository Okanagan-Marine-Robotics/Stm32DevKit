#include "testsensor.h" 

// Function to initialize the ultrasonic sensor
void initUltrasonic() {
    pinMode(TRIG_PIN, OUTPUT);  // Trigger pin as output
    pinMode(ECHO_PIN, INPUT);   // Echo pin as input
}

// Function to send the trigger pulse
void sendTriggerPulse() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
}

// Function to measure the duration of the echo pulse
long measureEchoDuration() {
    return pulseIn(ECHO_PIN, HIGH);  // Measure how long the echo pin stays HIGH
}

// Function to calculate the distance based on the echo duration
float calculateDistance(long duration) {
    return (duration * 0.0343) / 2;  // Speed of sound is 343m/s, or 0.0343 cm/µs
}

// Function to read ultrasonic sensor data
float readUltrasonicDistance() {
    sendTriggerPulse();             // Trigger the ultrasonic sensor
    long duration = measureEchoDuration();  // Measure echo duration
    return calculateDistance(duration);    // Calculate and return distance
}
