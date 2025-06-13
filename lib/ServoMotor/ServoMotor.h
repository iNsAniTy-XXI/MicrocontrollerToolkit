#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <Arduino.h>
#include <Servo.h>

class ServoMotor {
private:
    Servo servo;
    uint8_t pin;
    int currentAngle;
public:
    ServoMotor(uint8_t pin);
    void begin();
    void setAngle(int angle);
    int getAngle() const;
};

#endif // SERVO_MOTOR_H
