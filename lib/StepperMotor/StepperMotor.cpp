#include "StepperMotor.h"

const uint8_t DEFAULT_SEQUENCE[4][4] = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
};

StepperMotor::StepperMotor(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4) {
    _pins[0] = pin1;
    _pins[1] = pin2;
    _pins[2] = pin3;
    _pins[3] = pin4;
    setStepSequence(DEFAULT_SEQUENCE);
}

void StepperMotor::begin() {
    for (int i = 0; i < 4; ++i) {
        pinMode(_pins[i], OUTPUT);
        digitalWrite(_pins[i], LOW);
    }
}

void StepperMotor::setStepSequence(const uint8_t sequence[4][4]) {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            _stepSequence[i][j] = sequence[i][j];
}

void StepperMotor::setStep(int stepIdx) {
    for (int i = 0; i < 4; ++i) {
        digitalWrite(_pins[i], _stepSequence[stepIdx][i]);
    }
}

void StepperMotor::step(int steps, int speedMs) {
    int dir = (steps > 0) ? 1 : -1;
    steps = abs(steps);
    for (int s = 0; s < steps; ++s) {
        int stepIdx = (dir > 0) ? (s % 4) : (3 - (s % 4));
        setStep(stepIdx);
        delay(speedMs);
    }
    // Turn off all coils after stepping
    for (int i = 0; i < 4; ++i) digitalWrite(_pins[i], LOW);
}
