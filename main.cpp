#include "myobject.h"

int main() {
    MyObject sender;
    MyObject receiver;

    sender.m_intSignal.myConnect([&receiver](int intValue) { receiver.onIntSignal(intValue); });
    sender.m_stringSignal.myConnect([&receiver](std::string stringValue) { receiver.onStringSignal(stringValue); });
    sender.m_doubleAndBoolSignal.myConnect([&receiver](double doubleValue, bool flag) { receiver.onDoubleAndBoolSignal(doubleValue, flag); });

    sender.emitIntSignal(42);
    sender.emitStringSignal("Hello, world!");
    sender.emitDoubleAndBoolSignalAsync(3.14, true);

    return 0;
}
