#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include <Arduino.h>

class SevenSegment {
public:
    SevenSegment(const uint8_t segmentPins[8]);
    void begin();
    void displayDigit(uint8_t digit);
    void clear();
private:
    uint8_t _segmentPins[8];
    static const uint8_t digitToSegment[10];
};

#endif // SEVENSEGMENT_H
