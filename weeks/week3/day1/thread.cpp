#include <iostream>
#include <thread>
#include <chrono>

enum class EvenOdd{
    Even,
    Odd
};
void func(EvenOdd input){
    int i = input==EvenOdd::Even?0:1;

    for(;i<=10;){
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << i << "\n";
        i += 2;
    }
    std::cout << static_cast<int>(input) << ": " << std::this_thread::get_id();
}

void func1(const std::string& name){
    for(int i = 0; i <= 10; i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << name << " thread id: " << std::this_thread::get_id() << " id=" << i << "\n";
    }
}

int main() {
    std::thread t1(func1,"t1");
    std::thread t2(func1,"t2");

    std::cout << "main: " << std::this_thread::get_id() << "\n";


    // std::thread t1([](){std::cout << "I am thread t1\n";});
    // std::thread t2([](){std::cout << "I am thread t2\n";});

    t1.join();
    t2.join();
    return 0;
}