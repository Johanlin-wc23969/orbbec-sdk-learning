#include <iostream>
#include <optional>

std::optional<int> divide(int a, int b){
    if(b == 0) return std::nullopt;
    return a/b;
}

void example1(){
    auto result = divide(10,1);
    if(result){
        std::cout << "result(value()): " << result.value() << std::endl;
        std::cout << "result(*): " << *result << std::endl;
    }
    else{
        std::cout << "result invalid\n";
    }

    auto result2 = divide(10,1);
    std::cout << "output: " << result2.value_or(0);

}

int main() {
    example1();

    return 0;
}