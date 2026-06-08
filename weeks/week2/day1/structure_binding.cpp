#include <iostream>

struct Person
{
    int id;
    std::string name;
    int age;
};

void example1(){
    Person p{1,"johan",26};

    auto [id,name,age] = p;

    std::cout << "直接访问p对象" << "id:" << p.id << " name:" << p.name << " age:" << p.age << std::endl;
    std::cout << "拆解结构绑定" << "id:" << id << " name:" << name << " age:" << age << std::endl;
}

int main() {
    example1();

    return 0;
}

