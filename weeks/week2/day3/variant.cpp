#include <iostream>
#include <variant>
#include <string>

template<class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};

template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

void example1(){
    std::variant<int,std::string> data;
    data = "hello";
    std::visit(
        overloaded{
            [](const int& value){std::cout << "This is int\n";},
            [](const std::string& value){std::cout << "This is string\n";}
        },
        data
    );
}

int main() {
    example1();

    return 0;
}