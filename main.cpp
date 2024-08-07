#include "somepublisher.h"
#include "somesubscriber.h"

int main() {
    SomePublisher publisher;
    SomeSubscriber subscriber;

    publisher.m_intSignal.addSubscriber([&](int intValue) { subscriber.onIntSignal(intValue); });
    publisher.m_stringSignal.addSubscriber([&](std::string stringValue) { subscriber.onStringSignal(stringValue); });
    publisher.m_doubleAndBoolSignal.addSubscriber([&](double doubleValue, bool flag) { subscriber.onDoubleAndBoolSignal(doubleValue, flag); });
    publisher.m_doubleAndBoolSignal.addSubscriber(subscriber, &SomeSubscriber::onDoubleAndBoolSignal);
    publisher.emitIntSignal(42);
    publisher.emitStringSignal("Hello, world!");
    publisher.emitDoubleAndBoolSignalAsync(3.14, true);

    return 0;
}
