#include "Motor.h"

Motor::Motor(uint8_t pinA, uint8_t pinB) : _pinA(pinA), _pinB(pinB) {}

void Motor::begin() {
    pinMode(_pinA, OUTPUT);
    pinMode(_pinB, OUTPUT);
    stop();
}

void Motor::forward() {
    digitalWrite(_pinA, HIGH);
    digitalWrite(_pinB, LOW);
}

void Motor::backward() {
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, HIGH);
}

void Motor::stop() {
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, LOW);
}
