#ifndef MAX7219_DISPLAY_H
#define MAX7219_DISPLAY_H

#include <Arduino.h>
#include <SPI.h>

class MAX7219Display {
public:
    explicit MAX7219Display(uint8_t csPin);
    void begin();
    void sendCommand(uint8_t reg, uint8_t data);
    void clear();
    void setDigit(uint8_t digit, uint8_t value, bool dp = false);
    void setIntensity(uint8_t intensity); // 0-15
private:
    uint8_t _csPin;
};

#endif // MAX7219_DISPLAY_H
