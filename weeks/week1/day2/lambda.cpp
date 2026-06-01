#include <iostream>
#include <algorithm>
#include <vector>

void example1() {
    std::vector<int> distances{4,2,1,4,5,7,6,0,9,8,7,6};
    int target = 6;
    auto firstGreater = find_if(distances.begin(), distances.end(), [target](int d1){
        return d1 > target;
    });

    std::cout << *firstGreater;  
}

void example2() {
    std::vector<int> distances{4,2,1,4,5,7,6,0,9,8,7,6};
    int target = 6;
    auto closestDistance = min_element(distances.begin(), distances.end(), [target](int d1, int d2){
        return abs(d1-target) < abs(d2-target);
    });

    std::cout << *closestDistance;  
}

int main() {

    // example1();
    example2();
    return 0;
}