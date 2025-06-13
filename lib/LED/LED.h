#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED {
public:
    // Constructor to initialize the LED with a pin
    explicit LED(uint8_t pin);

    // Method to set the pin mode to OUTPUT
    void begin();

    // Method to turn on the LED
    void turnOn();

    // Method to turn off the LED
    void turnOff();

    // Method to toggle the LED state
    void toggle();

    // Method to check if the LED is on
    bool isOn() const;

private:
    uint8_t _pin;   // Pin number for the LED
    bool _state;    // Current state of the LED (on/off)
};

#endif