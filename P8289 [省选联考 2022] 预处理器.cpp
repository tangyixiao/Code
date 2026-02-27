#include <cctype>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// 全局宏表
unordered_map<string, string> macros;

// 判断字符是否为标识符字符（字母、数字、下划线）
bool isIdentifierChar(char c) { return isalnum(c) || c == '_'; }

// 宏展开函数
string expand(const string &text, set<string> &expanding) {
    string result;
    int n = text.length();

    for (int i = 0; i < n;) {
        // 如果是标识符字符
        if (isIdentifierChar(text[i])) {
            // 提取整个标识符
            int start = i;
            while (i < n && isIdentifierChar(text[i])) {
                i++;
            }
            string identifier = text.substr(start, i - start);

            // 检查是否需要展开
            if (macros.count(identifier) && !expanding.count(identifier)) {
                // 防止递归展开
                expanding.insert(identifier);
                result += expand(macros[identifier], expanding);
                expanding.erase(identifier);
            } else {
                result += identifier;
            }
        } else {
            // 非标识符字符，直接添加到结果
            result += text[i];
            i++;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        // 预处理命令
        if (!line.empty() && line[0] == '#') {
            istringstream iss(line);
            string cmd, name, content;
            iss >> cmd;

            if (cmd == "#define") {
                iss >> name;
                // 获取剩余内容作为宏的内容
                getline(iss, content);
                // 移除前导空格（如果有）
                if (!content.empty() && content[0] == ' ') {
                    content = content.substr(1);
                }
                macros[name] = content;
                cout << endl; // 输出空行
            } else if (cmd == "#undef") {
                iss >> name;
                macros.erase(name);
                cout << endl; // 输出空行
            }
        } else {
            // 普通文本，进行宏展开
            set<string> expanding; // 当前正在展开的宏集合
            cout << expand(line, expanding) << endl;
        }
    }

    return 0;
}