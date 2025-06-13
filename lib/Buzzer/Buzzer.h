#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
public:
    explicit Buzzer(uint8_t pin);
    void begin();
    void on();
    void off();
    void beep(unsigned int durationMs = 100);
    void playTone(unsigned int frequency, unsigned long durationMs = 0);
    void stopTone();
private:
    uint8_t _pin;
    bool _isOn;
};

#endif // BUZZER_H
