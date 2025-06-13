#include "ActiveBuzzer.h"

ActiveBuzzer::ActiveBuzzer(uint8_t pin) : _pin(pin), _isOn(false) {}

void ActiveBuzzer::begin() {
    pinMode(_pin, OUTPUT);
    off();
}

void ActiveBuzzer::on() {
    digitalWrite(_pin, HIGH);
    _isOn = true;
}

void ActiveBuzzer::off() {
    digitalWrite(_pin, LOW);
    _isOn = false;
}

void ActiveBuzzer::beep(unsigned int durationMs) {
    on();
    delay(durationMs);
    off();
}

bool ActiveBuzzer::isOn() const {
    return _isOn;
}
