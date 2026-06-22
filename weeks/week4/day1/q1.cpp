#include <vector>
#include <iostream>
#include <future>
#include <thread>
#include <algorithm>

int square(int x){
    if(x < 0) throw std::runtime_error("negative input");
    return x * x;
}
std::vector<int> processTasks(const std::vector<int>& tasks){
    std::vector<std::future<int>> fs;
    std::vector<std::jthread> thds;
    int size = tasks.size();
    fs.reserve(size);
    thds.reserve(size);

    for(int t : tasks){
        std::packaged_task<int(int)> task(square);

        fs.emplace_back(task.get_future());
        thds.emplace_back(std::move(task),t);
    }

    std::vector<int> res;
    res.reserve(size);

    for(auto& f : fs){
        try{
            res.push_back(f.get());
        }catch(...){
            res.push_back(-1);
        }
    }
    
    return res;
}

int main(){
    std::vector<int> tasks = {1, 2, 3, 4};
    auto res = processTasks(tasks);

    std::for_each(res.begin(), res.end(), [](int a){std::cout << a << "\n";});

    return 0;
}