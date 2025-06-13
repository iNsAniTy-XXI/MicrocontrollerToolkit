#include "ServoMotor.h"

ServoMotor::ServoMotor(uint8_t pin) : pin(pin), currentAngle(0) {}

void ServoMotor::begin() {
    servo.attach(pin);
    setAngle(0);
}

void ServoMotor::setAngle(int angle) {
    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;
    servo.write(angle);
    currentAngle = angle;
}

int ServoMotor::getAngle() const {
    return currentAngle;
}
