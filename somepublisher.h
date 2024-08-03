#pragma once

#include "signal.h"

class SomePublisher
{
public:
    Signal<int> m_intSignal;
    Signal<std::string> m_stringSignal;
    Signal<double, bool> m_doubleAndBoolSignal;

    void emitIntSignal(int value);
    void emitStringSignal(const std::string& value);
    void emitDoubleAndBoolSignalAsync(double value, bool flag);
};

