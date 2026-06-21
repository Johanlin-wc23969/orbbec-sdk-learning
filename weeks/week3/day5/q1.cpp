#include <future>
#include <vector>
#include <iostream>


std::future<int> calculatePositiveSumAsync(const std::vector<int>& nums){
    std::promise<int> p;
    std::future<int> f = p.get_future();
    
    std::thread t([](const std::vector<int>& nums, std::promise<int> p){
        int count = 0;
        for(auto n : nums){
            if(n <= 0) continue;
            count += n;
        }
        p.set_value(count);
    }, nums, std::move(p));

    t.detach();

    return f;
}

int main() {
    std::vector<int> nums = {1, -2, 3, 4, 0};
    auto f = calculatePositiveSumAsync(nums);
    std::cout << f.get();

    return 0;
}