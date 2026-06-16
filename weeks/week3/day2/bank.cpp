#include <iostream>
#include <thread>
#include <mutex>

class Bank{
public:
    int money = 0;;
    std::mutex mtx;
    void deposit(int amount);
    void withdraw(int amount);
};

void Bank::deposit(int amount){
    int current_money = 0;
    {
        std::lock_guard<std::mutex> lock(mtx);
        
        money += amount;
        current_money = money;
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "存款成功！已存入 " << amount << " 元，目前总金额 " << current_money << "\n";
    }
}
void Bank::withdraw(int amount){
    int current_money = 0;
    {
        std::lock_guard<std::mutex> lock(mtx);

        if(amount > money){
            std::cout << "取款失败！当前金额不足" << amount << "\n";
            return;
        }

        money -= amount;
        current_money = money;
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "取款成功！目前剩余总金额" << current_money << "\n";
    }
}

int main() {
    Bank bank;
    std::jthread t1(&Bank::deposit, &bank, 1000);
    std::jthread t2(&Bank::withdraw, &bank, 200);
    std::jthread t3(&Bank::withdraw, &bank, 900);


    return 0;
}