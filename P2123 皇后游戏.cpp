#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Minister {
    int a, b;
};

bool cmp_group1(const Minister &m1, const Minister &m2) {
    return m1.a < m2.a; // 第一组按 a 升序
}

bool cmp_group2(const Minister &m1, const Minister &m2) {
    return m1.b > m2.b; // 第二组按 b 降序
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Minister> group1, group2;
        for (int i = 0; i < n; ++i) {
            Minister m;
            cin >> m.a >> m.b;
            if (m.a <= m.b) {
                group1.push_back(m); // 第一组：a <= b
            } else {
                group2.push_back(m); // 第二组：a > b
            }
        }

        // 分别排序
        sort(group1.begin(), group1.end(), cmp_group1);
        sort(group2.begin(), group2.end(), cmp_group2);

        // 合并顺序：第一组在前，第二组在后
        vector<Minister> order;
        order.reserve(n);
        for (auto &m : group1)
            order.push_back(m);
        for (auto &m : group2)
            order.push_back(m);

        // 计算最大奖金
        ll prefix_sum = 0; // 前缀和：∑a
        ll c = 0;          // 前一个大臣的奖金
        ll max_c = 0;      // 记录最大值
        for (int i = 0; i < n; ++i) {
            prefix_sum += order[i].a;
            c = max(c, prefix_sum) + order[i].b;
            max_c = max(max_c, c);
        }

        cout << max_c << '\n';
    }

    return 0;
}