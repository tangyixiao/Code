#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, m, i, j, k;
long long h[N], dp[N][N / 3 + 5];

signed main() {
    scanf("%d %d", &m, &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &h[i]);
    }
    sort(h + 1, h + n + 1);
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            dp[i][j] = 1e18;
        }
    }
    for (i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            long long v = dp[i - 2][j - 1] + (h[i] - h[i - 1]) * (h[i] - h[i - 1]);
            if (v < dp[i][j]) {
                dp[i][j] = v;
            }
        }
    }
    printf("%lld\n", dp[n][m]);
    return 0;
}
