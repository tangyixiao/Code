#include <iostream>
using namespace std;
int main() {
    string ans[] = {
        "3880",                  // 双引号中替换为 A 题的答案
        "11",                    // 双引号中替换为 B 题的答案
        "2400",                  // 双引号中替换为 C 题的答案
        "1340",                  // 双引号中替换为 D 题的答案
        "491499994440019919104", // 双引号中替换为 E 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}
