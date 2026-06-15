#include <iostream>
#include <thread>



void func(int& count){
    for(int i = 0; i < 10000; i++){
        count++;
    }
}

int main() {
    int count = 0;
    std::thread t1(func,std::ref(count));
    std::thread t2(func,std::ref(count));

    t1.join();
    t2.join();

    std::cout << "count = " << count << "\n";

    return 0;
}