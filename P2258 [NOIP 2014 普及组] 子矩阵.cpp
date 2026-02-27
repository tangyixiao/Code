
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

const int MAXN = 16;
const int MAXM = 16;
const int INF = 1e9;

int a[MAXN][MAXM];        // 原始矩阵
int rows[MAXN];           // 当前选中的行索引
int col_diff[MAXM];       // 列内部的相邻行差值之和
int cost_row[MAXM][MAXM]; // 两列之间的行方向差值之和
int dp1[MAXM];            // DP 数组，滚动使用
int dp2[MAXM];

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = INF;
    // 枚举所有行选择状态
    for (int S = 0; S < (1 << n); S++) {
        if (__builtin_popcount(S) != r)
            continue;

        // 提取行索引
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (S & (1 << i)) {
                rows[idx++] = i;
            }
        }

        // 预处理 col_diff
        for (int j = 0; j < m; j++) {
            col_diff[j] = 0;
            for (int i = 0; i < r - 1; i++) {
                col_diff[j] += abs(a[rows[i]][j] - a[rows[i + 1]][j]);
            }
        }

        // 预处理 cost_row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                cost_row[j1][j2] = 0;
                for (int i = 0; i < r; i++) {
                    cost_row[j1][j2] += abs(a[rows[i]][j1] - a[rows[i]][j2]);
                }
            }
        }

        // 动态规划选择列
        for (int j = 0; j < m; j++) {
            dp1[j] = col_diff[j]; // 只选一列
        }

        int current_ans;
        if (c == 1) {
            current_ans = *min_element(dp1, dp1 + m);
        } else {
            for (int t = 2; t <= c; t++) {
                for (int j = 0; j < m; j++) {
                    dp2[j] = INF;
                    // 枚举前一列
                    for (int k = 0; k < j; k++) {
                        dp2[j] = min(dp2[j], dp1[k] + cost_row[k][j]);
                    }
                    dp2[j] += col_diff[j];
                }
                swap(dp1, dp2); // 滚动数组
            }
            current_ans = *min_element(dp1, dp1 + m);
        }
        ans = min(ans, current_ans);
    }

    cout << ans << endl;
    return 0;
}