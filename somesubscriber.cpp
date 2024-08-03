#include "somesubscriber.h"

void SomeSubscriber::onIntSignal(int value) {
    std::cout << "Received integer: " << value << std::endl;
}

void SomeSubscriber::onStringSignal(std::string value) {
    std::cout << "Received message: " << value << std::endl;
}

void SomeSubscriber::onDoubleAndBoolSignal(double value, bool flag) {
    std::cout << "Received double and bool signal (async): value = " << value << ", flag = " << std::boolalpha << flag << std::endl;
}
