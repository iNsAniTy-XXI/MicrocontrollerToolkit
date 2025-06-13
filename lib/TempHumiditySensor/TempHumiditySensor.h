#ifndef TEMP_HUMIDITY_SENSOR_H
#define TEMP_HUMIDITY_SENSOR_H

#include <Arduino.h>
#include <DHT.h>

class TempHumiditySensor {
public:
    TempHumiditySensor(uint8_t pin, uint8_t type = DHT11);
    void begin();
    float readTemperature(bool isFahrenheit = false);
    float readHumidity();
private:
    uint8_t _pin;
    uint8_t _type;
    DHT* _dht;
};

#endif // TEMP_HUMIDITY_SENSOR_H
