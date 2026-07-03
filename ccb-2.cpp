#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int r = std::rand() % 100 + 1;
    int user = 0;

    std::cout << r << std::endl;   // 调试用
    std::cout << "Guess the number between 1 and 100: ";

    while (std::cin >> user) {  //等用户输入一个整数，成功了才进入循环
        if (user > r) {
            std::cout << "Too high, try again: ";
        } else if (user < r) {
            std::cout << "Too low, try again: ";
        } else {
            std::cout << "You are right!" << std::endl;
            break;  //猜对，跳出，游戏结束
        }
        //循环体结束，自动回到 while 条件，再次执行 std::cin >> user，等待新输入
    }
    std::cin.get();
    std::cin.get();  // 暂停窗口，多一个 get 吃掉残留的换行符
}