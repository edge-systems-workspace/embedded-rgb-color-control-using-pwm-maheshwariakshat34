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
void loop() {

    // Digital mode
    digitalWrite(redPin, HIGH);
    delay(1000);
    digitalWrite(redPin, LOW);
    delay(1000);

    // PWM Red
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(1000);

    // PWM Green
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    delay(1000);

    // PWM Blue
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    delay(1000);
}