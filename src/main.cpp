#include <Arduino.h>

int redPin   = 9;
int greenPin = 10;
int bluePin  = 11;

void setup() {
    Serial.begin(9600);

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    Serial.println("RGB System Initialized");
}