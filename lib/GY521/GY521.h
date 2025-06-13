#ifndef GY521_H
#define GY521_H

#include <Arduino.h>
#include <Wire.h>

class GY521 {
public:
    explicit GY521(uint8_t address = 0x68);
    void begin();
    bool isConnected();
    void readRaw(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz);
    float readTemperature();
private:
    uint8_t _address;
    void _readRegisters(uint8_t reg, uint8_t *buf, uint8_t len);
};

#endif // GY521_H
