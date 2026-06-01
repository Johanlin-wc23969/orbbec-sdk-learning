#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <optional>

class Package{
public:
    int id;
    std::string city;
    float weight;
    float cost;

};

std::optional<int> example(){
    std::vector<Package> pkgs = {
        {101, "London", 3.5, 12.0},
        {102, "Paris",  7.2, 18.5},
        {103, "London", 8.0, 20.0},
        {104, "Berlin", 6.5, 15.0}
    };

    std::string target_city = "London";
    float target_weight = 5.0;

    auto answer = find_if(pkgs.begin(), pkgs.end(), [target_city, target_weight](const Package& pkg){ 
        return pkg.city == target_city && pkg.weight > target_weight;
    });

    if(answer == pkgs.end()) return std::nullopt;
    else return answer->id;
}

int main() {
    auto answer = example();
    return 0;
}