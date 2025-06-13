#include "GY521.h"

GY521::GY521(uint8_t address) : _address(address) {}

void GY521::begin() {
    Wire.begin();
    // Wake up MPU6050 (clear sleep bit)
    Wire.beginTransmission(_address);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission();
}

bool GY521::isConnected() {
    Wire.beginTransmission(_address);
    return (Wire.endTransmission() == 0);
}

void GY521::_readRegisters(uint8_t reg, uint8_t *buf, uint8_t len) {
    Wire.beginTransmission(_address);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom(_address, len, true);
    for (uint8_t i = 0; i < len; ++i) {
        buf[i] = Wire.read();
    }
}

void GY521::readRaw(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz) {
    uint8_t buf[14];
    _readRegisters(0x3B, buf, 14);
    ax = (buf[0] << 8) | buf[1];
    ay = (buf[2] << 8) | buf[3];
    az = (buf[4] << 8) | buf[5];
    gx = (buf[8] << 8) | buf[9];
    gy = (buf[10] << 8) | buf[11];
    gz = (buf[12] << 8) | buf[13];
}

float GY521::readTemperature() {
    uint8_t buf[2];
    _readRegisters(0x41, buf, 2);
    int16_t rawTemp = (buf[0] << 8) | buf[1];
    return (rawTemp / 340.0) + 36.53;
}
