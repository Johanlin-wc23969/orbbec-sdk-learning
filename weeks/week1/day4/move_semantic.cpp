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

class Buffer{
public:
    size_t size;
    int* data;

    // 构造函数
    Buffer(size_t size):size(size){
        data = new int[size];
    }

    // 析构函数
    ~Buffer(){
        delete[] data;
    }

    // 拷贝构造
    Buffer(const Buffer& other){
        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data+size, data);
    }

    // 移动构造
    Buffer(Buffer&& other){
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;
    }
};
int main() {
    example1();

    return 0;
}