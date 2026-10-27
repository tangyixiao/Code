#include <bits/stdc++.h>
using namespace std;

int n, m, i, j, cur0;
long long dp[12][1 << 12];

void dfs(int i, int j, int cur, int nxt) {
    if (j == m) {
        dp[i + 1][nxt] += dp[i][cur0];
        return;
    }
    if (cur & (1 << j)) {
        dfs(i, j + 1, cur, nxt);
        return;
    }
    if (j + 1 < m && !(cur & (1 << (j + 1)))) {
        dfs(i, j + 2, cur | (1 << j) | (1 << (j + 1)), nxt);
    }
    dfs(i, j + 1, cur | (1 << j), nxt | (1 << j));
}

signed main() {
    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 && m == 0) {
            break;
        }
        if (n < m) {
            int t = n;
            n = m;
            m = t;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (i = 0; i < n; i++) {
            for (cur0 = 0; cur0 < (1 << m); cur0++) {
                if (dp[i][cur0] != 0) {
                    dfs(i, 0, cur0, 0);
                }
            }
        }
        printf("%lld\n", dp[n][0]);
    }
    return 0;
}
