#include <iostream>
#include <thread>
#include <mutex>

void func(int& count, std::mutex& mutex){
    for(int i = 0; i < 100000; i++){
        mutex.lock();
        count++;
        mutex.unlock();
    }
}

int main() {
    int count = 0;
    std::mutex mtx;

    std::thread t1(func,std::ref(count),std::ref(mtx));
    std::thread t2(func,std::ref(count),std::ref(mtx));

    t1.join();
    t2.join();

    std::cout << "count = " << count << '\n';

    return 0;
}