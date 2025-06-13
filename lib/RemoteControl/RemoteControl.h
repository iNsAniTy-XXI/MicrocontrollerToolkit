#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <Arduino.h>
#include <IRremote.h>

class RemoteControl {
public:
    explicit RemoteControl(uint8_t recvPin);
    void begin();
    bool isButtonPressed();
    unsigned long getButtonCode();
    void resume();
private:
    uint8_t _recvPin;
    IRrecv* _irrecv;
    decode_results _results;
    bool _hasData;
};

#endif // REMOTE_CONTROL_H
