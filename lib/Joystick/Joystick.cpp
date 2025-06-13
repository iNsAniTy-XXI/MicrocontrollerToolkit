#include "Joystick.h"

Joystick::Joystick(uint8_t pinX, uint8_t pinY, uint8_t pinButton)
    : _pinX(pinX), _pinY(pinY), _pinButton(pinButton) {}

void Joystick::begin() {
    pinMode(_pinX, INPUT);
    pinMode(_pinY, INPUT);
    pinMode(_pinButton, INPUT_PULLUP);
}

int Joystick::readX() {
    return analogRead(_pinX);
}

int Joystick::readY() {
    return analogRead(_pinY);
}

bool Joystick::isPressed() {
    return digitalRead(_pinButton) == LOW;
}
