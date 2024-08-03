#pragma once

#include <iostream>

class SomeSubscriber
{
public:
    void onIntSignal(int value);
    void onStringSignal(std::string value);
    void onDoubleAndBoolSignal(double value, bool flag);
};

