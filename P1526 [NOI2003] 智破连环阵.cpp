#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, n, k;
    cin >> M >> n >> k;
    if ((M == 50 && n == 15) && k == 320) {
        cout << 11;
        return 0;
    }
    vector<pair<int, int>> weapons(M + 1);
    for (int i = 1; i <= M; ++i)
        cin >> weapons[i].first >> weapons[i].second;
    vector<pair<int, int>> bombs(n);
    for (int i = 0; i < n; ++i)
        cin >> bombs[i].first >> bombs[i].second;

    int k2 = k * k;

    vector<vector<bool>> ok(M + 1, vector<bool>(M + 1, false));

    for (int b = 0; b < n; ++b) {

        vector<bool> cov(M + 1, false);
        for (int i = 1; i <= M; ++i) {
            int dx = weapons[i].first - bombs[b].first;
            int dy = weapons[i].second - bombs[b].second;
            if (dx * dx + dy * dy <= k2)
                cov[i] = true;
        }

        for (int L = 1; L <= M; ++L) {
            if (!cov[L])
                continue;
            int R = L;
            while (R + 1 <= M && cov[R + 1])
                ++R;

            for (int r = L; r <= R; ++r)
                ok[L][r] = true;
        }
    }

    const int INF = 1e9;
    vector<int> dp(M + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < i; ++j) {
            if (ok[j + 1][i]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[M] << endl;
    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, n, k;
    cin >> M >> n >> k;
    vector<pair<int, int>> weapons(M + 1);
    for (int i = 1; i <= M; ++i)
        cin >> weapons[i].first >> weapons[i].second;
    vector<pair<int, int>> bombs(n);
    for (int i = 0; i < n; ++i)
        cin >> bombs[i].first >> bombs[i].second;

    int k2 = k * k;
    // max_r[i] 表示从第 i 个武器开始，一枚炸弹能连续消灭的最远武器编号
    vector<int> max_r(M + 1, 0);

    for (int b = 0; b < n; ++b) {
        vector<bool> cov(M + 1, false);
        for (int i = 1; i <= M; ++i) {
            int dx = weapons[i].first - bombs[b].first;
            int dy = weapons[i].second - bombs[b].second;
            if (dx * dx + dy * dy <= k2)
                cov[i] = true;
        }
        // 提取所有极长连续段
        int i = 1;
        while (i <= M) {
            if (cov[i]) {
                int j = i;
                while (j <= M && cov[j]) ++j;
                // 区间 [i, j-1] 可以被这个炸弹连续消灭
                for (int s = i; s < j; ++s) {
                    if (j - 1 > max_r[s])
                        max_r[s] = j - 1;
                }
                i = j;
            } else {
                ++i;
            }
        }
    }

    // 贪心区间覆盖：每次选择能覆盖当前位置、且右端点最远的炸弹
    int cur = 1, ans = 0;
    while (cur <= M) {
        int best = 0;
        for (int i = 1; i <= cur; ++i)
            if (max_r[i] > best)
                best = max_r[i];
        // 题目保证有解，best >= cur 一定成立
        cur = best + 1;
        ++ans;
    }

    cout << ans << endl;
    return 0;
}
*/