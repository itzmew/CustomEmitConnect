#pragma once

#include "signal.h"
#include <iostream>

class MyObject {
public:
    Signal<int> m_intSignal;
    Signal<std::string> m_stringSignal;
    Signal<double, bool> m_doubleAndBoolSignal;

    void onIntSignal(int value);
    void onStringSignal(std::string value);
    void onDoubleAndBoolSignal(double value, bool flag);

    void emitIntSignal(int value);
    void emitStringSignal(const std::string& value);
    void emitDoubleAndBoolSignalAsync(double value, bool flag);
};
