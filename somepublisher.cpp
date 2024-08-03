#include "somepublisher.h"

void SomePublisher::emitIntSignal(int value) {
    m_intSignal.notify(value);
}

void SomePublisher::emitStringSignal(const std::string& value) {
    m_stringSignal.notify(value);
}

void SomePublisher::emitDoubleAndBoolSignalAsync(double value, bool flag) {
    m_doubleAndBoolSignal.notifyAsync(value, flag);
}
