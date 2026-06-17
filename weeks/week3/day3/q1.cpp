#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>


class TaskQueue{
public:
    using Task = std::function<void()>;
    void push(Task task);
    std::optional<Task> pop();
    void shutdown();
private:
    std::queue<Task> tasks_;
    std::mutex mtx_;
    std::condition_variable cv_;
    bool stopped_ = false;
};

void TaskQueue::push(Task task){
    {
        std::lock_guard<std::mutex> lock(mtx_);
        if(stopped_) return;
        tasks_.push(std::move(task));
    }

    cv_.notify_one();
    std::cout << "完成push任务，notify_one\n";
}

void TaskQueue::shutdown(){
    {
        std::lock_guard<std::mutex> lock(mtx_);
        stopped_ = true;
    }

    cv_.notify_all();
    std::cout << "notify_all 关闭队列\n";
}

std::optional<TaskQueue::Task> TaskQueue::pop(){
    std::unique_lock<std::mutex> lock(mtx_);
    cv_.wait(lock,[&]{return stopped_ || !tasks_.empty();});

    if(stopped_ && tasks_.empty()) return std::nullopt;

    Task t = std::move(tasks_.front());
    tasks_.pop();
    return t;
}


void worker(TaskQueue& q, std::string thread){
    while(true){
        auto task = q.pop();
        if(!task) break;
        (*task)();
        std::cout << thread << " is doing a work\n";
    }
}

int main(){
    TaskQueue q;
    std::jthread t1(worker,std::ref(q),"t1");
    std::jthread t2(worker,std::ref(q),"t2");
    std::jthread t3(worker,std::ref(q),"t3");

    q.push([]{
        std::cout << "Pushing Task A\n";
    });

    q.push([]{
        std::cout << "Pushing Task B\n";
    });

    q.push([]{
        std::cout << "Pushing Task C\n";
    });

    q.shutdown();

    return 0;
}