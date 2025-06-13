#ifndef RFID_MODULE_H
#define RFID_MODULE_H

#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

class RFIDModule {
public:
    RFIDModule(uint8_t ssPin, uint8_t rstPin);
    void begin();
    bool isCardPresent();
    bool readCardUID(String &uid);
private:
    uint8_t _ssPin;
    uint8_t _rstPin;
    MFRC522 *_mfrc522;
};

#endif // RFID_MODULE_H
