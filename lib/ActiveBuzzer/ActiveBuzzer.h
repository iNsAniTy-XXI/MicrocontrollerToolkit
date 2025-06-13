#ifndef ACTIVE_BUZZER_H
#define ACTIVE_BUZZER_H

#include <Arduino.h>

class ActiveBuzzer {
public:
    explicit ActiveBuzzer(uint8_t pin);
    void begin();
    void on();
    void off();
    void beep(unsigned int durationMs = 100);
    bool isOn() const;
private:
    uint8_t _pin;
    bool _isOn;
};

#endif // ACTIVE_BUZZER_H
