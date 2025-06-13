#include "Relay.h"

Relay::Relay(uint8_t pin, bool activeHigh) : _pin(pin), _activeHigh(activeHigh), _state(false) {}

void Relay::begin() {
    pinMode(_pin, OUTPUT);
    off();
}

void Relay::on() {
    digitalWrite(_pin, _activeHigh ? HIGH : LOW);
    _state = true;
}

void Relay::off() {
    digitalWrite(_pin, _activeHigh ? LOW : HIGH);
    _state = false;
}

void Relay::toggle() {
    if (_state) {
        off();
    } else {
        on();
    }
}

bool Relay::isOn() const {
    return _state;
}
