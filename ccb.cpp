#include <iostream>      // 标准输入输出流：cin, cout
#include <cstdlib>       // 通用工具：srand, rand, atoi
#include <ctime>         // 时间函数：time(0)
using namespace std;     // 使用标准命名空间，让 cin/cout 不用写 std::

int main() {
    srand(time(0));// 用当前时间作为随机数种子，确保每次运行结果不同
    int r = rand() % 100 + 1;    // 生成 1~100 的随机整数
    char user_a[10];    // 字符数组用来存放输入的字符串（最多9个有效字符 + '\0'）
    //cout << r << endl;
    cout << "guess the number between 1 and 100" << endl;
    // 第一次猜测
    cin >> user_a;                // 把用户输入当成字符串读入 user_a
    int user = atoi(user_a);      // atoi 把字符串转换成整数，无法转换时返回 0
    // 当猜测的数字不等于答案时，循环继续
    while (user != r) {
        // 根据猜测结果给出提示
        if (user > r) {
            cout << "too high, try again:" << endl;
        } else if (user < r) {
            cout << "too low, try again:" << endl;
        }
        // 无论提示什么，都统一在这里读取下一次猜测
        cin >> user_a;
        user = atoi(user_a);      // 再次转换，没有重新定义 int user（避免变量遮蔽）
    }
    cout << "you are right" << endl;
    cin.get();
}