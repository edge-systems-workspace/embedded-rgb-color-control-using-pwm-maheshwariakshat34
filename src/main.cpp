/**
 * @file main.cpp
 * @brief RGB LED Color Control using PWM
 *
 * This program controls an RGB LED using PWM (Pulse Width Modulation) signals.
 * It cycles through different color combinations by modulating the intensity
 * of each color channel (Red, Green, Blue) independently.
 *
 * @author Akshat Maheshwari
 * @version 1.0
 * @date 2026-02-28
 *
 * @details
 * - Red LED is connected to pin 9
 * - Green LED is connected to pin 10
 * - Blue LED is connected to pin 11
 * - All PWM values range from 0 (off) to 255 (full brightness)
 * - The program demonstrates digital control and PWM-based analog control
 */

#include <Arduino.h>

/**
 * @brief GPIO pin number for the red LED channel
 * @note Must be a PWM-capable pin (3, 5, 6, 9, 10, or 11 on Arduino Uno)
 */
int redPin   = 9;

/**
 * @brief GPIO pin number for the green LED channel
 * @note Must be a PWM-capable pin (3, 5, 6, 9, 10, or 11 on Arduino Uno)
 */
int greenPin = 10;

/**
 * @brief GPIO pin number for the blue LED channel
 * @note Must be a PWM-capable pin (3, 5, 6, 9, 10, or 11 on Arduino Uno)
 */
int bluePin  = 11;

/**
 * @brief Initialize the RGB LED system
 *
 * This function is called once at startup. It initializes:
 * - Serial communication at 9600 baud rate for debugging
 * - GPIO pins for the red, green, and blue LEDs as OUTPUT
 * - Prints a startup message to the Serial monitor
 *
 * @return void
 *
 * @see Arduino::Serial::begin
 * @see Arduino::pinMode
 */
void setup() {
    Serial.begin(9600);

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    Serial.println("RGB System Initialized");
}

/**
 * @brief Main loop controlling RGB LED color sequences
 *
 * This function runs repeatedly after setup() completes. It cycles through
 * different color combinations:
 * 1. Digital mode: Red LED toggled on/off (1 second each)
 * 2. Pure Red: Full brightness red, green and blue off
 * 3. Pure Green: Full brightness green, red and blue off
 * 4. Pure Blue: Full brightness blue, red and green off
 *
 * Each color display lasts 1 second (1000 milliseconds).
 *
 * @return void
 *
 * @see Arduino::digitalWrite
 * @see Arduino::analogWrite
 * @see Arduino::delay
 */
void loop() {

    /**
     * @brief Digital mode operation
     *
     * Demonstrates basic digital control by toggling the red LED
     * on and off with 1 second intervals using digitalWrite().
     * This shows the difference between digital (on/off) and
     * analog (PWM) control modes.
     */
    // Digital mode
    digitalWrite(redPin, HIGH);
    delay(1000);
    digitalWrite(redPin, LOW);
    delay(1000);

    /**
     * @brief Red color demonstration
     *
     * Sets the RGB LED to pure red by:
     * - Red channel: 255 (full brightness)
     * - Green channel: 0 (off)
     * - Blue channel: 0 (off)
     */
    // PWM Red
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(1000);

    /**
     * @brief Green color demonstration
     *
     * Sets the RGB LED to pure green by:
     * - Red channel: 0 (off)
     * - Green channel: 255 (full brightness)
     * - Blue channel: 0 (off)
     */
    // PWM Green
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    delay(1000);

    /**
     * @brief Blue color demonstration
     *
     * Sets the RGB LED to pure blue by:
     * - Red channel: 0 (off)
     * - Green channel: 0 (off)
     * - Blue channel: 255 (full brightness)
     */
    // PWM Blue
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    delay(1000);
}