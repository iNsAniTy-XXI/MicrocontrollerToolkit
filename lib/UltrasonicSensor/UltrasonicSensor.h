#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>
#include "../../include/Enums/MeasurementUnit.h"

class UltrasonicSensor {
    public:
        UltrasonicSensor(int trigPin, int echoPin, MeasurementUnit format);
        long readDistance();
        String stringify(long distance);
        void changeMeasurementUnit(MeasurementUnit format);
    private:
        int _trigPin;
        int _echoPin;
        MeasurementUnit _format;
        void sendPulse();
};

#endif
