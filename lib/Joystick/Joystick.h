#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class Joystick {
public:
    Joystick(uint8_t pinX, uint8_t pinY, uint8_t pinButton);
    void begin();
    int readX();
    int readY();
    bool isPressed();
private:
    uint8_t _pinX;
    uint8_t _pinY;
    uint8_t _pinButton;
};

#endif // JOYSTICK_H
