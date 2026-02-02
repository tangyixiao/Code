#include <cctype>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<long long> nums;    // 用于存储数字的栈
    long long num = 0;        // 用于构建当前数字
    bool buildingNum = false; // 是否正在构建数字

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // 如果是数字，则继续构建数字
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            buildingNum = true;
        }
        // 遇到点号表示数字结束，将数字入栈
        else if (c == '.') {
            if (buildingNum) {
                nums.push(num);
                num = 0;
                buildingNum = false;
            }
        }
        // 遇到运算符，进行计算
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // 弹出两个操作数
            long long b = nums.top();
            nums.pop();
            long long a = nums.top();
            nums.pop();

            long long result = 0;

            // 根据运算符进行计算
            switch (c) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b; // C++整数除法本身就是向0取整
                break;
            }

            // 将计算结果入栈
            nums.push(result);
        }
        // 遇到@结束符，停止处理
        else if (c == '@') {
            break;
        }
    }

    // 输出最终结果
    cout << nums.top() << endl;

    return 0;
}