#ifndef SOUND_SENSOR_H
#define SOUND_SENSOR_H

#include <Arduino.h>

class SoundSensor {
private:
    uint8_t pin;
public:
    SoundSensor(uint8_t pin);
    void begin();
    int read();
    bool isSoundDetected(int threshold = 500);
};

#endif // SOUND_SENSOR_H
