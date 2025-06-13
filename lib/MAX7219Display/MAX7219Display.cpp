#include "MAX7219Display.h"

MAX7219Display::MAX7219Display(uint8_t csPin) : _csPin(csPin) {}

void MAX7219Display::begin() {
    pinMode(_csPin, OUTPUT);
    SPI.begin();
    sendCommand(0x09, 0xFF); // Decode mode: all digits
    sendCommand(0x0A, 0x0F); // Intensity: max
    sendCommand(0x0B, 0x07); // Scan limit: 8 digits
    sendCommand(0x0C, 0x01); // Shutdown register: normal operation
    sendCommand(0x0F, 0x00); // Display test: off
    clear();
}

void MAX7219Display::sendCommand(uint8_t reg, uint8_t data) {
    digitalWrite(_csPin, LOW);
    SPI.transfer(reg);
    SPI.transfer(data);
    digitalWrite(_csPin, HIGH);
}

void MAX7219Display::clear() {
    for (uint8_t i = 1; i <= 8; ++i) {
        setDigit(i - 1, 0xF); // Blank
    }
}

void MAX7219Display::setDigit(uint8_t digit, uint8_t value, bool dp) {
    if (digit > 7) return;
    uint8_t v = value & 0x0F;
    if (dp) v |= 0x80;
    sendCommand(digit + 1, v);
}

void MAX7219Display::setIntensity(uint8_t intensity) {
    if (intensity > 15) intensity = 15;
    sendCommand(0x0A, intensity);
}
