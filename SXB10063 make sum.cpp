#include <bits/stdc++.h>
using namespace std;
const int N = 30005;
int t, n, i, j, x, tot;
long long dp[N], ans;
int a[35];
signed main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i <= N - 1; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        tot = 0;
        for (i = 1; i <= n; i++) {
            for (j = tot; j >= 0; j--) {
                if (dp[j] > 0) {
                    dp[j + a[i]] += dp[j];
                }
            }
            tot += a[i];
        }
        ans = 0;
        for (i = 1; i <= n; i++) {
            if (dp[a[i]] >= 1) {
                ans += dp[a[i]] - 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
