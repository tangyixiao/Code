#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, i, j, k, len, a[N], c[N][N], dp[N][N];
signed main() {
    while (scanf("%d", &n) == 1) {
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 1; i <= n; i++) {
            c[i][i] = a[i] % 100, dp[i][i] = 0;
        }
        for (len = 2; len <= n; len++) {
            for (i = 1; i + len - 1 <= n; i++) {
                j = i + len - 1;
                c[i][j] = (c[i][i] + c[i + 1][j]) % 100;
                dp[i][j] = 1e9;
                for (k = i; k < j; k++) {
                    int t = dp[i][k] + dp[k + 1][j] + c[i][k] * c[k + 1][j];
                    if (t < dp[i][j]) {
                        dp[i][j] = t;
                    }
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
