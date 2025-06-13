#include "TempHumiditySensor.h"

TempHumiditySensor::TempHumiditySensor(uint8_t pin, uint8_t type)
    : _pin(pin), _type(type), _dht(nullptr) {}

void TempHumiditySensor::begin() {
    if (_dht == nullptr) {
        _dht = new DHT(_pin, _type);
    }
    _dht->begin();
}

float TempHumiditySensor::readTemperature(bool isFahrenheit) {
    if (!_dht) return NAN;
    return isFahrenheit ? _dht->readTemperature(true) : _dht->readTemperature(false);
}

float TempHumiditySensor::readHumidity() {
    if (!_dht) return NAN;
    return _dht->readHumidity();
}
