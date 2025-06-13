#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include <Arduino.h>

class MotionSensor {
public:
    explicit MotionSensor(uint8_t pin);
    void begin();
    bool isMotionDetected();
private:
    uint8_t _pin;
};

#endif // MOTION_SENSOR_H
