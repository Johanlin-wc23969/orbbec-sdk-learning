#include <iostream> 
#include <map>
#include <vector>
#include <string>
#include <algorithm>

struct Record{
    std::string name;
    std::string course;
    float score;
};

std::map<std::string, std::pair<std::string,float>> findTopStudentByCourse(const std::vector<Record>& records){
    std::map<std::string, std::pair<std::string,float>> mp;
    for(const auto& [name,course,score] : records){
        auto it = mp.find(course);
        if(it == mp.end()){
            mp[course] = {name,score};
        }else{
            const auto& [top_name,top_score] = it->second;
            if(top_score < score){
                it->second = {name,score};
            }
        }
    }
    return mp;
}

void example1(){
    std::vector<Record> records{
        {"Tom", "Math", 90},
        {"Jack", "Math", 95},
        {"Lucy", "English", 88},
        {"Alice", "English", 92}
    };

    const auto& top_students_by_course = findTopStudentByCourse(records);
    for(const auto& [course,student] : top_students_by_course){
        const auto& [name,score] = student;
        std::cout << course << ": " << name << " " << score << std::endl;
    }
}

int main() {
    example1();

    return 0;
}