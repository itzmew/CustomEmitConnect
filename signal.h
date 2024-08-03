#pragma once

#include <vector>
#include <functional>
#include <future>
#include <thread>
#include <mutex>

template<typename... Args>
class Signal {
public:
    using SubscriberType = std::function<void(Args... args)>;

    void addSubscriber(const SubscriberType& subscriber) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_subscribers.emplace_back(subscriber);
    }

    void notify(Args... args) const {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (const auto& subscriber : m_subscribers) {
            subscriber(args...);
        }
    }

    void notifyAsync(Args... args) const {
        std::vector<std::future<void>> futures;

        {
            std::lock_guard<std::mutex> lock(m_mutex);
            for (const auto& subscriber : m_subscribers) {
                futures.emplace_back(std::async(std::launch::async, [subscriber, args...]() {
                    subscriber(args...);
                }));
            }
        }

        for (auto& future : futures) {
            future.wait();
        }
    }

private:
    mutable std::mutex m_mutex;
    std::vector<SubscriberType> m_subscribers;
};
