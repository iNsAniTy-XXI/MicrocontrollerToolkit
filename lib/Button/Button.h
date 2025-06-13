#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
private:
    uint8_t pin;
    bool lastState;
    bool currentState;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
public:
    Button(uint8_t pin, unsigned long debounceDelay = 50);
    void begin();
    void update();
    bool isPressed();
};

#endif // BUTTON_H
