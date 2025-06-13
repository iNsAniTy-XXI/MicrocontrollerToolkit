#include "RemoteControl.h"

RemoteControl::RemoteControl(uint8_t recvPin) : _recvPin(recvPin), _irrecv(nullptr), _hasData(false) {}

void RemoteControl::begin() {
    if (_irrecv == nullptr) {
        _irrecv = new IRrecv(_recvPin);
    }
    _irrecv->enableIRIn();
}

bool RemoteControl::isButtonPressed() {
    if (!_irrecv) return false;
    _hasData = _irrecv->decode(&_results);
    return _hasData;
}

unsigned long RemoteControl::getButtonCode() {
    if (_hasData) {
        return _results.value;
    }
    return 0;
}

void RemoteControl::resume() {
    if (_irrecv) {
        _irrecv->resume();
    }
}
