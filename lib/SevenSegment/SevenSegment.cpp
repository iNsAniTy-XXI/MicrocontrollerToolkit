#include "SevenSegment.h"

const uint8_t SevenSegment::digitToSegment[10] = {
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

SevenSegment::SevenSegment(const uint8_t segmentPins[8]) {
    for (int i = 0; i < 8; ++i) _segmentPins[i] = segmentPins[i];
}

void SevenSegment::begin() {
    for (int i = 0; i < 8; ++i) pinMode(_segmentPins[i], OUTPUT);
    clear();
}

void SevenSegment::displayDigit(uint8_t digit) {
    if (digit > 9) return;
    uint8_t seg = digitToSegment[digit];
    for (int i = 0; i < 8; ++i) {
        digitalWrite(_segmentPins[i], (seg >> i) & 0x01);
    }
}

void SevenSegment::clear() {
    for (int i = 0; i < 8; ++i) digitalWrite(_segmentPins[i], LOW);
}
