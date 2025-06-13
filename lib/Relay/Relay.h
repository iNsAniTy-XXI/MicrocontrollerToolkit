#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class Relay {
public:
    explicit Relay(uint8_t pin, bool activeHigh = true);
    void begin();
    void on();
    void off();
    void toggle();
    bool isOn() const;
private:
    uint8_t _pin;
    bool _activeHigh;
    bool _state;
};

#endif // RELAY_H
