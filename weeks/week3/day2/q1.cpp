#include <iostream>
#include <thread>
#include <mutex>


void func(const std::string& id, int& count, std::mutex& mtx){
    for(int i = 0; i < 25000; i++){
        {
            std::lock_guard<std::mutex> lock(mtx);
            count ++;
        }
    }
    std::cout << "id=" << id << " thread_id=" << std::this_thread::get_id() << " ending\n";
}

int main() {
    int count = 0;
    std::mutex mtx;
    std::thread t1(func, "1", std::ref(count), std::ref(mtx));
    std::thread t2(func, "2", std::ref(count), std::ref(mtx));
    std::thread t3(func, "3", std::ref(count), std::ref(mtx));
    std::thread t4(func, "4", std::ref(count), std::ref(mtx));


    t1.join();
    t2.join();
    t3.join();
    t4.join();


    std::cout << "count=" << count << "\n";

    return 0;
}