#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Dwarf {
    int a, b;
};

bool cmp(const Dwarf &x, const Dwarf &y) { return x.a + x.b < y.a + y.b; }

int main() {
    int n;
    cin >> n;
    vector<Dwarf> d(n);
    int sumA = 0;
    for (int i = 0; i < n; ++i) {
        cin >> d[i].a >> d[i].b;
        sumA += d[i].a;
    }
    int H;
    cin >> H;

    // 按照 a+b 从小到大排序
    sort(d.begin(), d.end(), cmp);

    // dp[j] 表示逃跑了 j 个人后，剩余总高度的最大值
    vector<int> dp(n + 1, -INF);
    dp[0] = sumA;

    for (int i = 0; i < n; ++i) {
        // 倒序更新，确保使用上一层的状态
        for (int j = i + 1; j >= 1; --j) {
            if (dp[j - 1] + d[i].b >= H) {
                dp[j] = max(dp[j], dp[j - 1] - d[i].a);
            }
        }
    }

    // 找到最大的 j 使得 dp[j] 非负
    int ans = 0;
    for (int j = n; j >= 0; --j) {
        if (dp[j] >= 0) {
            ans = j;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}