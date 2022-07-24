#include <iostream>


int main() {
    /*
    int width(5);   //直接初始化，但是不能用于所有类型
    int height{5};  //大括号初始化，更为一致的初始化机制，尽可能使用大括号进行初始化
    int value{};    //值初始化，一般会将变量初始化为0或空
     */
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    std::cout << "You entered " << x << '\n';
    return 0;
}
