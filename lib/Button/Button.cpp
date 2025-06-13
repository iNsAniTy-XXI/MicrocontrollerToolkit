#include "Button.h"

Button::Button(uint8_t pin, unsigned long debounceDelay) : pin(pin), debounceDelay(debounceDelay), lastState(LOW), currentState(LOW), lastDebounceTime(0) {}

void Button::begin() {
    pinMode(pin, INPUT);
    lastState = digitalRead(pin);
    currentState = lastState;
}

void Button::update() {
    bool reading = digitalRead(pin);
    if (reading != lastState) {
        lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != currentState) {
            currentState = reading;
        }
    }
    lastState = reading;
}

bool Button::isPressed() {
    return currentState == HIGH;
}
