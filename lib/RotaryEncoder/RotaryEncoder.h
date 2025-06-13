#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <Arduino.h>

class RotaryEncoder {
public:
    RotaryEncoder(uint8_t pinA, uint8_t pinB, uint8_t buttonPin);
    void begin();
    int read();
    bool isButtonPressed();
private:
    uint8_t _pinA, _pinB, _buttonPin;
    int _position;
    int _lastStateA;
};

#endif // ROTARY_ENCODER_H
