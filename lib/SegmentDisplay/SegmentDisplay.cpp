#include "SegmentDisplay.h"

const uint8_t SegmentDisplay::digitToSegment[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

SegmentDisplay::SegmentDisplay(const uint8_t digitPins[4], const uint8_t segmentPins[8]) {
    for (int i = 0; i < 4; ++i) _digitPins[i] = digitPins[i];
    for (int i = 0; i < 8; ++i) _segmentPins[i] = segmentPins[i];
}

void SegmentDisplay::begin() {
    for (int i = 0; i < 4; ++i) pinMode(_digitPins[i], OUTPUT);
    for (int i = 0; i < 8; ++i) pinMode(_segmentPins[i], OUTPUT);
    clear();
}

void SegmentDisplay::displayDigit(uint8_t digit, uint8_t value) {
    for (int i = 0; i < 4; ++i) digitalWrite(_digitPins[i], i == digit ? LOW : HIGH);
    for (int i = 0; i < 8; ++i) digitalWrite(_segmentPins[i], (value >> i) & 0x01);
    delay(2); // Small delay for persistence
}

void SegmentDisplay::displayNumber(int number) {
    int n = number;
    for (int d = 3; d >= 0; --d) {
        uint8_t digit = n % 10;
        displayDigit(d, digitToSegment[digit]);
        n /= 10;
    }
}

void SegmentDisplay::clear() {
    for (int i = 0; i < 4; ++i) digitalWrite(_digitPins[i], HIGH);
    for (int i = 0; i < 8; ++i) digitalWrite(_segmentPins[i], LOW);
}
