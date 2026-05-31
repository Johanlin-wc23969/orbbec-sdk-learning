#include <iostream>

void referenceExample() {
    int a = 10;
    int& ref = a; 
    int& new_ref = ref; // ❌ 不允许二次引用 int&& new_ref = ref; ｜ ✅ 但可以 int& new_ref = ref; (此时的ref 在编译器看来是a本身 因为ref只是a的别名)


    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of ref: " << ref << std::endl;
    std::cout << "Value of new_ref: " << new_ref << std::endl;
}

void constExample() {
    const int a = 10;
    int b = a;

    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of b: " << b << std::endl;
}

int main(){
    // referenceExample();
    constExample();

    return 0;
}