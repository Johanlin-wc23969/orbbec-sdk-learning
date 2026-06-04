#include <iostream>
#include <memory>

class Person{
public:
    Person(){
        std::cout << "ctor\n";
    }
    ~Person(){
        std::cout << "dtor\n";
    }
};

void example1() {
    auto p = std::make_unique<Person>();
    std::cout << "example函数结束\n";
}

void example2() {
    auto p1 = std::make_unique<Person>();
    auto p2 = std::move(p1);
    if(p1 == nullptr) std::cout << "p1 = nullptr \n";
    if(p2 != nullptr) std::cout << "p2 = Person实例 \n";
}

void example3() {
    auto p1 = std::make_shared<Person>();
    std::cout << "创建p1 - p1计数: " << p1.use_count() << std::endl;

    auto p2 = p1;
    std::cout << "p2共享p1 - p1计数: " << p1.use_count() << std::endl;

    auto p3 = p2;
    std::cout << "p3共享p1- p1计数: " << p1.use_count() << std::endl;

    auto p4 = std::make_shared<Person>();
    std::cout << "创建p4 - p4计数: " << p4.use_count() << std::endl;

    p2 = p4;
    std::cout << "p2共享p4 - p1计数: " << p1.use_count() << std::endl;
    std::cout << "p2共享p4 - p4计数: " << p4.use_count() << std::endl;

    p3 = p4;
    std::cout << "p3共享p4 - p1计数: " << p1.use_count() << std::endl;
    std::cout << "p3共享p4 - p4计数: " << p4.use_count() << std::endl;

    p2.reset();
    std::cout << "p2重置 - p4计数: " << p4.use_count() << std::endl;
    p3.reset();
    std::cout << "p3重置 - p4计数: " << p4.use_count() << std::endl;
}

class B;
class A {
public:
    std::shared_ptr<B> b;
    ~A(){
        std::cout << "A-dtor\n";
    }
};
class B {
public:
    std::shared_ptr<A> a;
     ~B(){
        std::cout << "B-dtor\n";
    }
};
void example4(){
    auto a = std::shared_ptr<A>();
    auto b = std::shared_ptr<B>();

    a->b = b;
    b->a = a;
    std::cout << "建立循环引用\n";

    a->b.use_count();
    b->a.use_count();
}

class User;
class Room{
public:
    std::vector<std::weak_ptr<User>> user_ptrs;
};

class User{
public:
    std::string name;
    User(std::string name):name(std::move(name)){};

    std::weak_ptr<Room> room_ptr;
};

void example5(){
    auto r = std::make_shared<Room>();
    auto u = std::make_shared<User>("Johan");

    r->user_ptrs.push_back(u);
    u->room_ptr = r;
}


int main() {
    // example1();
    // example2();
    // example3();
    // example4();
    example5();
    return 0;
}