#include <iostream>

class User;
class Room{
public:
    std::string name;
    Room(std::string name):name(name){};
    std::vector<std::shared_ptr<User>> user_ptr_list;
};

class User{
public:
    std::string name;
    User(std::string name):name(name){};
    std::weak_ptr<Room> room;
};

bool joinRoom(const std::shared_ptr<Room>& room, const std::weak_ptr<User>& user){
    std::shared_ptr<User> user_ptr = user.lock();
    room->user_ptr_list.push_back(user_ptr);
    user_ptr->room = room;
    return true;
}

int main() {
    auto u = std::make_shared<User>("Johan");
    auto r = std::make_shared<Room>("C++ Study Room");
    
    bool result = joinRoom(r,u);

    std::cout << result << std::endl;
    if(r->user_ptr_list.size() == 1) std::cout << "room has 1 user \n";
    if(r->user_ptr_list[0]->name == "Johan") std::cout << "the user in the room is Johan\n";
    if(u->room.lock() == r) std::cout << "the user recorded the room\n";

    return 0;
}