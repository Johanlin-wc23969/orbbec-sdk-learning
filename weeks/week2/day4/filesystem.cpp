#include <iostream>
#include <filesystem>

void example(){
    std::filesystem::path p("学习笔记.md");

    std::cout << "file path: " << p << std::endl;

    std::cout << "file extension: " << p.extension() << std::endl;

    if(std::filesystem::exists("学习笔记.md")){
        std::cout << "file exists" << std::endl;
    }else std::cout << "file not exist" << std::endl;

    if(std::filesystem::is_directory(p)){
        std::cout << "[DIR]" << p << std::endl;
    }
    if(std::filesystem::is_regular_file(p)){
        std::cout << "[FIlE]" << p << std::endl;
    }
    std::cout << "parent directory: " << p.parent_path() << "\n";

    std::cout << std::filesystem::file_size(p) << "\n";

    // std::filesystem::create_directory("test/folder2");

    // std::filesystem::create_directories("test1/folder1");

    // std::filesystem::remove("test1");

    // std::filesystem::remove_all("test");

    // std::filesystem::copy_file("test/学习笔记.md","学习笔.md");

    // std::filesystem::rename("学习笔.md","学习笔记.md");

    int count_cpp = 0;
    for(const auto& entry : std::filesystem::directory_iterator(".")){
        auto p = entry.path();
        if(p.extension() == ".cpp"){
            std::cout << p.filename() << "\n";
            count_cpp++;
        }
    }
    std::cout << "一共有" << count_cpp << "个cpp文件\n";



}

int main() {
    example();

    return 0;
}