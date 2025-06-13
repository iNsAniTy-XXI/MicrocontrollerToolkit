#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer {
public:
    explicit Potentiometer(uint8_t pin);
    void begin();
    int readRaw();
    float readVoltage(float referenceVoltage = 5.0);
private:
    uint8_t _pin;
};

#endif // POTENTIOMETER_H
