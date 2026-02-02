#include <bits/stdc++.h>
#include <ext/rope> // 需要包含这个头文件
using namespace std;
using namespace __gnu_cxx; // rope在这个命名空间中

const int MAXN = 80005;
rope<int> rp;  // 使用rope存储书序列
int pos[MAXN]; // 记录每本书在rope中的位置（下标）
int rev[MAXN]; // 记录每个位置上书的编号

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 初始化
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        rp.push_back(x); // 将书加入rope
    }

    // 构建初始的位置映射
    for (int i = 0; i < n; i++) {
        int book = rp[i];
        pos[book] = i;
        rev[i] = book;
    }

    while (m--) {
        string op;
        cin >> op;

        if (op == "Top") {
            int s;
            cin >> s;
            int p = pos[s];
            // 删除这本书
            rp.erase(p, 1);
            // 插入到最前面
            rp.insert(0, s);
            // 更新位置信息
            pos[s] = 0;
            // 更新rev数组（这里需要重新构建或者使用更高效的方法）
            // 由于操作次数较多，这里使用直接遍历更新
            for (int i = 0; i < rp.size(); i++) {
                pos[rp[i]] = i;
            }
        } else if (op == "Bottom") {
            int s;
            cin >> s;
            int p = pos[s];
            // 删除这本书
            rp.erase(p, 1);
            // 插入到最后面
            rp.push_back(s);
            // 更新位置信息
            pos[s] = rp.size() - 1;
            // 更新rev数组
            for (int i = 0; i < rp.size(); i++) {
                pos[rp[i]] = i;
            }
        } else if (op == "Insert") {
            int s, t;
            cin >> s >> t;
            int p = pos[s];

            if (t == 0)
                continue; // 位置不变

            // 计算目标位置
            int target = p + t;

            // 确保target在有效范围内
            if (target < 0)
                target = 0;
            if (target >= rp.size())
                target = rp.size() - 1;

            // 删除原位置的书
            rp.erase(p, 1);
            // 插入到新位置
            rp.insert(target, s);

            // 更新位置信息
            for (int i = 0; i < rp.size(); i++) {
                pos[rp[i]] = i;
            }
        } else if (op == "Ask") {
            int s;
            cin >> s;
            cout << pos[s] << "\n"; // 位置从0开始计数
        } else if (op == "Query") {
            int s;
            cin >> s;
            s--; // 转换为0-based索引
            cout << rp[s] << "\n";
        }
    }

    return 0;
}