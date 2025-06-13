#ifndef SEGMENT_DISPLAY_H
#define SEGMENT_DISPLAY_H

#include <Arduino.h>

class SegmentDisplay {
public:
    SegmentDisplay(const uint8_t digitPins[4], const uint8_t segmentPins[8]);
    void begin();
    void displayNumber(int number);
    void clear();
private:
    uint8_t _digitPins[4];
    uint8_t _segmentPins[8];
    void displayDigit(uint8_t digit, uint8_t value);
    static const uint8_t digitToSegment[10];
};

#endif // SEGMENT_DISPLAY_H
