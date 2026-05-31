#include<iostream>


void decltypeExample() {
    int a = 10;
    int &ref = a; 
    decltype(a) b = 20; // decltype(a) 的类型是int
    decltype(ref) c = ref; // decltype(ref) 的类型是int&，ref的声明类型（引用）
    decltype((a)) d = a; // decltype((a)) 的类型是int&, (a) 是一个表达式，代表 a 变量本身 而不是a的类型
    decltype((ref)) e = ref; // decltype((ref)) 的类型是int&, (ref) 是一个表达式，代表 ref 变量本身就是 a 因此和 decltype((a)) 的类型一样
    decltype((a+1)) f = a + 1; // decltype((a+1)) 的类型是int， (a+1)是一个表达式，而这个表达式的结果是一个右值 而不是a变量本身，因此是int
}
int main() {
    decltypeExample();
    return 0;
}