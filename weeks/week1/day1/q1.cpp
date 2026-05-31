#include <iostream>
#include <algorithm>
class Order {
public:
    Order(int orderId, int userId, float cost, bool paymentStatus, std::vector<std::string> productsList) 
        : orderId(orderId), userId(userId), cost(cost), paymentStatus(paymentStatus), productsList(productsList) {}
    bool isAvailableOrder(float minimumCost, std::string targetProduct) const {
        return isPaid() && isGreaterthanMinimumCost(minimumCost) && includeTargetProduct(targetProduct);
    }
    int getId() const {
        return orderId;
    }

private:
    int orderId;
    int userId;
    float cost;
    bool paymentStatus;
    std::vector<std::string> productsList;

    bool isPaid() const {
        return paymentStatus;
    }
    bool isGreaterthanMinimumCost(float minimumCost) const {
        return cost >= minimumCost;
    }
    bool includeTargetProduct(std::string& targetProduct) const {
        return find(productsList.begin(), productsList.end(), targetProduct) != productsList.end();
    }
};

std::vector<Order> getAvailableOrders(std::vector<Order>& allOrders, float minimumCost, std::string& targetProduct) {
    std::vector<Order> availableOrders;
    for(const auto& order : allOrders){
        if(order.isAvailableOrder(minimumCost,targetProduct)) availableOrders.push_back(order);
    }
    return availableOrders;
}

void example1() {
    std::vector<Order> orders = {
        {1, 101, 99.9, true,  {"book", "cpp"}},
        {2, 102, 49.9, true,  {"book"}},
        {3, 103, 199.0, false, {"cpp"}},
        {4, 104, 150.0, true, {"cpp", "course"}}
    };
    int minAmount = 100.0;
    std::string targetTag = "cpp";

    std::vector<Order> availableOrders = getAvailableOrders(orders, minAmount, targetTag);

    for(const auto& order : availableOrders){
        std::cout << order.getId() << " ";
    }
    std::cout << std::endl;
}

void example2() {
    std::vector<Order> orders = {
        {10, 201, 300.0, true, {"phone", "digital"}},
        {11, 202, 120.0, true, {"book"}},
        {12, 203, 500.0, true, {"digital", "vip"}}
    };

    float minAmount = 200.0;
    std::string targetTag = "digital";

    std::vector<Order> availableOrders = getAvailableOrders(orders, minAmount, targetTag);

    for(const auto& order : availableOrders){
        std::cout << order.getId() << " ";
    }
    std::cout << std::endl;
}

int main() {
    example1();
    example2();
    return 0;
}