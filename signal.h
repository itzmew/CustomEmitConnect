#pragma once

#include <vector>
#include <functional>
#include <future>
#include <thread>
#include <mutex>

template<typename... Args>
class Signal {
public:
    using SlotType = std::function<void(Args... args)>;

    void myConnect(const SlotType& slot) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_slots.emplace_back(slot);
    }

    void myEmit(Args... args) const {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (const auto& slot : m_slots) {
            slot(args...);
        }
    }

    void myEmitAsync(Args... args) const {
        std::vector<std::future<void>> futures;

        {
            std::lock_guard<std::mutex> lock(m_mutex);
            for (const auto& slot : m_slots) {
                futures.emplace_back(std::async(std::launch::async, [slot, args...]() {
                    slot(args...);
                }));
            }
        }

        for (auto& future : futures) {
            future.wait();
        }
    }

private:
    mutable std::mutex m_mutex;
    std::vector<SlotType> m_slots;
};
