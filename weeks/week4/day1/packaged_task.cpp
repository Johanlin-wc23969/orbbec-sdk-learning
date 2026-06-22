#include <thread>
#include <iostream>
#include <future>
#include <functional>

int add(int a, int b){
    return a + b;
}

int multiply(int a, int b){
    return a * b;
}
void example1(){
    std::packaged_task<int(int,int)> task(multiply);
    std::future<int> f = task.get_future();
    std::jthread t(std::move(task),2,10);

    int res = f.get();

    std::cout << res;
}

void example2(){
    std::packaged_task<std::string()> task([](){
        return std::string("Hello world!");
    });
    std::future<std::string> f = task.get_future();
    std::jthread t(std::move(task));

    std::cout << f.get();
}

int main(){
    std::packaged_task<int(int,int)> task(add);
    std::future<int> f = task.get_future();

    // std::jthread t(std::move(task),10,20);
    task(10,20);

    std::cout << f.get();

    example1();
    example2();
    example3();


    return 0;
}