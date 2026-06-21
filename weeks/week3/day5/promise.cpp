#include <iostream>
#include <thread>
#include <future>

void example1(){
    std::promise<int> p;
    std::future<int> f = p.get_future();

    p.set_value(10);
    std::cout << "future 获取结果：" << f.get() << std::endl;
}


void worker(std::promise<int> p){
    int count = 0;
    for(int i = 1; i <= 100; i++){
        count += i;
    }
    p.set_value(count);
}
void example2(){
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::jthread t(worker,std::move(p)); // 因为promise只能set_value()一次 无法复用 所以直接move转移到函数参数，外部直接丢弃
    auto res = f.get();
    std::cout << "res = " << res << "\n";
}

int main() {
    example2();


    return 0;
}