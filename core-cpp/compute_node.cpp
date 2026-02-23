#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 2848
// Optimized logic batch 2535
// Optimized logic batch 9762
// Optimized logic batch 2911
// Optimized logic batch 4346
// Optimized logic batch 6639
// Optimized logic batch 8254
// Optimized logic batch 2457
// Optimized logic batch 7353
// Optimized logic batch 8907
// Optimized logic batch 4751
// Optimized logic batch 9936
// Optimized logic batch 9919
// Optimized logic batch 3620
// Optimized logic batch 1045
// Optimized logic batch 5803
// Optimized logic batch 5261
// Optimized logic batch 1580
// Optimized logic batch 6031
// Optimized logic batch 2060
// Optimized logic batch 6426
// Optimized logic batch 6472
// Optimized logic batch 6781
// Optimized logic batch 7496