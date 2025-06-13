#include "SoundSensor.h"

SoundSensor::SoundSensor(uint8_t pin) : pin(pin) {}

void SoundSensor::begin() {
    pinMode(pin, INPUT);
}

int SoundSensor::read() {
    return analogRead(pin);
}

bool SoundSensor::isSoundDetected(int threshold) {
    return read() > threshold;
}
