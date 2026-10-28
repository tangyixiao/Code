#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
int n, m, t, i, j, dp[N][N];
signed main() {
    scanf("%d%d", &n, &m);
    t = n, n = m, m = t;
    dp[0][0] = 1;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (!dp[i][j]) {
                continue;
            }
            if (i + 1 <= n && j + 2 <= m) {
                dp[i + 1][j + 2] = (dp[i + 1][j + 2] + dp[i][j]) % MOD;
            }
            if (i + 1 <= n && j - 2 >= 0) {
                dp[i + 1][j - 2] = (dp[i + 1][j - 2] + dp[i][j]) % MOD;
            }
            if (i + 2 <= n && j + 1 <= m) {
                dp[i + 2][j + 1] = (dp[i + 2][j + 1] + dp[i][j]) % MOD;
            }
            if (i + 2 <= n && j - 1 >= 0) {
                dp[i + 2][j - 1] = (dp[i + 2][j - 1] + dp[i][j]) % MOD;
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
