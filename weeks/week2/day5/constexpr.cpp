#include <iostream>


struct Point{
    int x;
    int y;

    constexpr Point(int a, int b) : x(a), y(b){}

    constexpr int sum() const {
        return x + y;
    }
};

constexpr int factorial(int n){
    int res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

int main(){
    constexpr int size = 100;
    int arr[size];

    // int x,y;
    // std::cin >> x;
    // std::cin >> y;

    // Point p(x,y);
    // std::cout << p.sum();

    std::cout << factorial(10);


    return 0;
}