#include "LED.h"
#include <Arduino.h>

LED::LED(uint8_t pin) : _pin(pin), _state(false) {}

void LED::begin() {
    pinMode(_pin, OUTPUT);
    turnOff();
}

void LED::turnOn() {
    digitalWrite(_pin, HIGH);
    _state = true;
}

void LED::turnOff() {
    digitalWrite(_pin, LOW);
    _state = false;
}

void LED::toggle() {
    if (_state) {
        turnOff();
    } else {
        turnOn();
    }
}

bool LED::isOn() const {
    return _state;
}