#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB, uint8_t buttonPin)
    : _pinA(pinA), _pinB(pinB), _buttonPin(buttonPin), _position(0), _lastStateA(LOW) {}

void RotaryEncoder::begin() {
    pinMode(_pinA, INPUT);
    pinMode(_pinB, INPUT);
    pinMode(_buttonPin, INPUT_PULLUP);
    _lastStateA = digitalRead(_pinA);
}

int RotaryEncoder::read() {
    int stateA = digitalRead(_pinA);
    if (stateA != _lastStateA) {
        if (digitalRead(_pinB) != stateA) {
            _position++;
        } else {
            _position--;
        }
    }
    _lastStateA = stateA;
    return _position;
}

bool RotaryEncoder::isButtonPressed() {
    return digitalRead(_buttonPin) == LOW;
}
