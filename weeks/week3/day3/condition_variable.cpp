#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

void producer(std::mutex& mtx, std::condition_variable& cv, int& work){
    while(1){
        {
            std::lock_guard<std::mutex> lock(mtx);
            work+=3;
            std::cout << "生产者完成生产，当前剩余work " << work << '\n';
        }
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void consumer(std::mutex& mtx, std::condition_variable& cv, int& work){
    while(1){
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,[&work]{return work > 0;});
            work--;
            std::cout << "消费者完成消耗，当前剩余work " << work << '\n';
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main() {
    std::mutex mtx;
    std::condition_variable cv;
    int work = 0;
    
    std::jthread consumer1_thread(consumer,std::ref(mtx),std::ref(cv),std::ref(work));
    std::jthread consumer2_thread(consumer,std::ref(mtx),std::ref(cv),std::ref(work));
    std::jthread consumer3_thread(consumer,std::ref(mtx),std::ref(cv),std::ref(work));
    std::jthread producer_thread(producer,std::ref(mtx),std::ref(cv),std::ref(work));


    return 0;
}