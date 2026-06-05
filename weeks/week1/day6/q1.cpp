#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

struct Task {
    int id;
    std::string title;
    int priority;
    bool finished;

    Task(int i, const std::string& t, int p)
        : id(i), title(t), priority(p), finished(false) {}
};


int main() {
    std::vector<std::unique_ptr<Task>> tasks;

    tasks.emplace_back(std::make_unique<Task>(1, "Write report", 3));
    tasks.emplace_back(std::make_unique<Task>(2, "Fix bug", 5));
    tasks.emplace_back(std::make_unique<Task>(3, "Reply email", 1));
    tasks.emplace_back(std::make_unique<Task>(4, "Code review", 4));

    std::sort(tasks.begin(), tasks.end(), [](const std::unique_ptr<Task>& a, const std::unique_ptr<Task>& b){ return a->priority < b->priority;});

    std::cout << "All tasks:" << std::endl;

    for (const auto& t : tasks) {
        std::cout << t->id << " "
                    << t->title << " "
                    << t->priority << std::endl;
    }

    
    auto found = std::find_if(tasks.begin(), tasks.end(), [](const std::unique_ptr<Task>& a){ return a->priority >= 4});

    if (found != tasks.end()) {
        (*found)->finished = true;
        std::cout << "Finished task: " << (*found)->title << std::endl;
    }

    return 0;
}