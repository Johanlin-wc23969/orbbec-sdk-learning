#include <iostream>

void func(int& x){
    std::cout << "参数是左值引用\n";
}

void func(int&& x){
    std::cout << "参数是右值引用\n";
}

void example1(){
    int x = 10;
    func(x);
    func(std::move(x));
    func(10);

}
int main() {
    example1();

    return 0;
}