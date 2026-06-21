#include <iostream>
#include <thread>
#include <future>



void work(std::promise<int> p){
    p.set_value(100);
}
int main(){
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::jthread t1(work,std::move(p));
    std::cout << f.get() << "\n";

    return 0;
}