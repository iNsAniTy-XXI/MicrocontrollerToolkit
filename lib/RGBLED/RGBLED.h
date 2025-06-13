#ifndef RGB_LED_H
#define RGB_LED_H

#include <Arduino.h>

class RGBLED {
public:
    RGBLED(uint8_t pinR, uint8_t pinG, uint8_t pinB, bool commonAnode = false);
    void begin();
    void setColor(uint8_t r, uint8_t g, uint8_t b);
    void off();
private:
    uint8_t _pinR, _pinG, _pinB;
    bool _commonAnode;
    uint8_t _applyPolarity(uint8_t value) const;
};

#endif // RGB_LED_H
