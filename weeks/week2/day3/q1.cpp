#include <iostream>

struct FixedPrice
{
    double price;
};

struct DiscountPrice
{
    double originalPrice;
    double discount;
};

struct MemberPrice
{
    double price;
    std::string memberLevel;
};

using Price = std::variant<FixedPrice,DiscountPrice,MemberPrice>;

struct OrderItem
{
    int quantity;
    Price price;
};

// overloaded 
template<class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

double calculateTotalPrice(const std::vector<OrderItem>& items){
    double total_price = 0;

    for(const auto& [quantity,price] : items){
        double current_price = std::visit(
            overloaded{
                [](const FixedPrice& p){
                    return p.price;
                },
                [](const DiscountPrice& p){
                    return p.originalPrice * p.discount;
                },
                [](const MemberPrice& p){
                    return p.price;
                }
            },
            price
        );
        total_price += quantity * current_price;

    }

    return total_price;
}

void example(){
    std::vector<OrderItem> items = {
        {2, FixedPrice{10.0}},
        {1, DiscountPrice{100.0, 0.8}},
        {3, MemberPrice{20.0, "gold"}}
    };
    double total_price = calculateTotalPrice(items);

    std::cout << "总价：" << total_price << std::endl;
}

int main() {
    example();

    return 0;
}

