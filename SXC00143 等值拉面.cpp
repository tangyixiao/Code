#include <bits/stdc++.h>
using namespace std;
const int N = 6005;
int n, i, j, a, b, tot, best, bestc;
int dp[N], tp[N];
signed main() {
    scanf("%d", &n);
    for (i = 0; i < N; i++) {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    tot = 0;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        tot += a + b;
        for (j = 0; j < N; j++) {
            tp[j] = 1e9;
        }
        for (j = 0; j < N; j++) {
            if (dp[j] >= 1e9) {
                continue;
            }
            if (j + a < N && dp[j] < tp[j + a]) {
                tp[j + a] = dp[j];
            }
            if (j + b < N && dp[j] + 1 < tp[j + b]) {
                tp[j + b] = dp[j] + 1;
            }
        }
        for (j = 0; j < N; j++) {
            dp[j] = tp[j];
        }
    }
    best = 1e9;
    bestc = 1e9;
    for (j = 0; j < N; j++) {
        if (dp[j] >= 1e9) {
            continue;
        }
        int c = abs(2 * j - tot);
        if (c < best || (c == best && dp[j] < bestc)) {
            best = c;
            bestc = dp[j];
        }
    }
    printf("%d\n", bestc);
    return 0;
}
