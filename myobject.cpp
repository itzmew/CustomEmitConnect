#include "myobject.h"

void MyObject::emitIntSignal(int value) {
    m_intSignal.myEmit(value);
}

void MyObject::onIntSignal(int value) {
    std::cout << "Received integer: " << value << std::endl;
}

void MyObject::emitStringSignal(const std::string& value) {
    m_stringSignal.myEmit(value);
}

void MyObject::onStringSignal(std::string value) {
    std::cout << "Received message: " << value << std::endl;
}

void MyObject::emitDoubleAndBoolSignalAsync(double value, bool flag) {
    m_doubleAndBoolSignal.myEmitAsync(value, flag);
}

void MyObject::onDoubleAndBoolSignal(double value, bool flag) {
    std::cout << "Received double and bool signal (async): value = " << value << ", flag = " << std::boolalpha << flag << std::endl;
}
