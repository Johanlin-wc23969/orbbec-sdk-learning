#include <iostream>
#include <future>


int square(int x){
    return x * x;
}
void example(){
    auto future = std::async(std::launch::async,square,5);
    int res = future.get();
    std::cout << "result: " << res << std::endl;
}

void example2(){
    auto future1 = std::async(std::launch::deferred,[](){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return 5;
    });
    auto future2 = std::async(std::launch::deferred,[](){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 5;
    });
    auto future3 = std::async(std::launch::deferred,[](){
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return 5;
    });

    int res = future1.get() + future2.get() + future3.get();
    std::cout << "result: " << res << std::endl;
}

void example3(){
    auto future = std::async(std::launch::async, [&](){
        std::this_thread::sleep_for(std::chrono::seconds(5));
    });

    while(future.wait_for(std::chrono::seconds(1)) != std::future_status::ready){
        std::cout << "Downloading...\n";
    }
}

int main(){
    // example();
    example2();
    // example3();

    return 0;
}