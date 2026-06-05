#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Room;

class User {
public:
    std::string name;
    std::weak_ptr<Room> room;

    User(const std::string& n)
        : name(n)
    {
    }
};

class Room : public std::enable_shared_from_this<Room> {
public:
    std::string roomName;
    std::vector<std::weak_ptr<User>> users;

    Room(const std::string& name)
        : roomName(name)
    {
    }

    void addUser(const std::shared_ptr<User>& user){
        if(user == nullptr) return;

        users.push_back(user);
        u->room = shared_from_this();
    }
};

int main()
{
    auto cppRoom = std::make_shared<Room>("Modern C++");

    auto u1 = std::make_shared<User>("Tom");
    auto u2 = std::make_shared<User>("Alice");
    auto u3 = std::make_shared<User>("Jack");

    cppRoom->addUser(u1);
    cppRoom->addUser(u2);
    cppRoom->addUser(u3);

    std::cout << "Users:" << std::endl;

    for(auto& user : cppRoom->users)
    {
        auto u = user.lock();
        if(u == nullptr) continue;
        std::cout << u->name << std::endl;
    }

    std::string s = "Alice";
    auto found = std::find_if(cppRoom->users.begin(), cppRoom->users.end(), [&s](const auto& user){ 
        auto u = user.lock();
        if(u != nullptr){
            return u->name == s;
        }
        return false;
    });


    if(found != cppRoom->users.end())
    {
        auto f = (*found).lock();
        if(f == nullptr) return 0;
        std::cout << "Found user: "
                  << f->name
                  << std::endl;
    }

    return 0;
}