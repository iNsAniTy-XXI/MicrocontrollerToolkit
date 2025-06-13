#include "Potentiometer.h"

Potentiometer::Potentiometer(uint8_t pin) : _pin(pin) {}

void Potentiometer::begin() {
    pinMode(_pin, INPUT);
}

int Potentiometer::readRaw() {
    return analogRead(_pin);
}

float Potentiometer::readVoltage(float referenceVoltage) {
    return (analogRead(_pin) / 1023.0) * referenceVoltage;
}
