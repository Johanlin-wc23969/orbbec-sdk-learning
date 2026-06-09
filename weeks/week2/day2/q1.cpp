#include <iostream>
#include <algorithm>
#include <optional>

std::optional<std::string> findConfigValue(const std::vector<std::pair<std::string,std::string>>& configs, const std::string& key){
    for(const auto& [k,v] : configs){
        if(k == key) return v;
    }
    return std::nullopt;
}

void example(){
    std::vector<std::pair<std::string,std::string>> configs = {
        {"theme", "dark"},
        {"nickname", ""}
    };
    std::string key = "font";

    auto result = findConfigValue(configs,key);
    if(result) std::cout << result.value() << std::endl;
    else std::cout << "not found\n";

}

int main() {
    example();

    return 0;
}