#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>

class StepperMotor {
public:
    StepperMotor(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4);
    void begin();
    void step(int steps, int speedMs = 5);
    void setStepSequence(const uint8_t sequence[4][4]);
private:
    uint8_t _pins[4];
    uint8_t _stepSequence[4][4];
    void setStep(int stepIdx);
};

#endif // STEPPER_MOTOR_H
