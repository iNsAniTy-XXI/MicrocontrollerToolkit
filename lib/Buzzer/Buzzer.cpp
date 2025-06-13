#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin) : _pin(pin), _isOn(false) {}

void Buzzer::begin() {
    pinMode(_pin, OUTPUT);
    off();
}

void Buzzer::on() {
    digitalWrite(_pin, HIGH);
    _isOn = true;
}

void Buzzer::off() {
    digitalWrite(_pin, LOW);
    _isOn = false;
}

void Buzzer::beep(unsigned int durationMs) {
    on();
    delay(durationMs);
    off();
}

void Buzzer::playTone(unsigned int frequency, unsigned long durationMs) {
    tone(_pin, frequency, durationMs);
    _isOn = true;
}

void Buzzer::stopTone() {
    noTone(_pin);
    _isOn = false;
}
