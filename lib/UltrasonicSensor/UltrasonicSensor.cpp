#include <Arduino.h>
#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin, MeasurementUnit format) {
    _trigPin = trigPin;
    _echoPin = echoPin;
    _format = format;

    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

void UltrasonicSensor::sendPulse() {
    // Stabilize the signal
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);

    // Send the pulse
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
}

long UltrasonicSensor::readDistance() {
    sendPulse();
    long duration = pulseIn(_echoPin, HIGH);

    switch(_format){
        case MeasurementUnit::Centimeters:
            return (duration / 2) / 29.1;

        case MeasurementUnit::Inches:
            return (duration / 2) / 74;

        case MeasurementUnit::Feet:
            return (duration / 2) / 888;
    }
}

String UltrasonicSensor::stringify(long distance) {
    String buffer = String(distance);
    switch(_format){
        case MeasurementUnit::Centimeters:
            buffer += " cm";
            break;

        case MeasurementUnit::Inches:
            buffer += " in";
            break;

        case MeasurementUnit::Feet:
            buffer += " ft";
            break;
    }

    return buffer;
}

void UltrasonicSensor::changeMeasurementUnit(MeasurementUnit format) {
    _format = format;
}
