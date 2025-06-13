#include "RGBLED.h"

RGBLED::RGBLED(uint8_t pinR, uint8_t pinG, uint8_t pinB, bool commonAnode)
    : _pinR(pinR), _pinG(pinG), _pinB(pinB), _commonAnode(commonAnode) {}

void RGBLED::begin() {
    pinMode(_pinR, OUTPUT);
    pinMode(_pinG, OUTPUT);
    pinMode(_pinB, OUTPUT);
    off();
}

uint8_t RGBLED::_applyPolarity(uint8_t value) const {
    return _commonAnode ? 255 - value : value;
}

void RGBLED::setColor(uint8_t r, uint8_t g, uint8_t b) {
    analogWrite(_pinR, _applyPolarity(r));
    analogWrite(_pinG, _applyPolarity(g));
    analogWrite(_pinB, _applyPolarity(b));
}

void RGBLED::off() {
    setColor(0, 0, 0);
}
