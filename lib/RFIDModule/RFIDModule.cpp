#include "RFIDModule.h"

RFIDModule::RFIDModule(uint8_t ssPin, uint8_t rstPin)
    : _ssPin(ssPin), _rstPin(rstPin), _mfrc522(nullptr) {}

void RFIDModule::begin() {
    SPI.begin();
    if (_mfrc522 == nullptr) {
        _mfrc522 = new MFRC522(_ssPin, _rstPin);
    }
    _mfrc522->PCD_Init();
}

bool RFIDModule::isCardPresent() {
    if (!_mfrc522) return false;
    return _mfrc522->PICC_IsNewCardPresent() && _mfrc522->PICC_ReadCardSerial();
}

bool RFIDModule::readCardUID(String &uid) {
    if (!_mfrc522) return false;
    if (!_mfrc522->PICC_IsNewCardPresent() || !_mfrc522->PICC_ReadCardSerial()) return false;
    uid = "";
    for (byte i = 0; i < _mfrc522->uid.size; i++) {
        if (i > 0) uid += ":";
        if (_mfrc522->uid.uidByte[i] < 0x10) uid += "0";
        uid += String(_mfrc522->uid.uidByte[i], HEX);
    }
    uid.toUpperCase();
    _mfrc522->PICC_HaltA();
    return true;
}
