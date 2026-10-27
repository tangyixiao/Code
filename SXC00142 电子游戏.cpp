#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long NEG = -1e18;
int n, V, i, j, g, p, gc, gv;
long long dp[N], f[N], ans;
signed main() {
    scanf("%d%d", &n, &V);
    for (i = 0; i <= V; i++) {
        dp[i] = 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%d%d", &p, &g);
        for (j = 0; j <= V; j++) {
            f[j] = j >= p ? dp[j - p] : NEG;
        }
        for (j = 0; j < g; j++) {
            scanf("%d%d", &gc, &gv);
            for (int w = V; w >= gc; w--) {
                if (f[w - gc] != NEG && f[w - gc] + gv > f[w]) {
                    f[w] = f[w - gc] + gv;
                }
            }
        }
        for (j = 0; j <= V; j++) {
            if (f[j] > dp[j]) {
                dp[j] = f[j];
            }
            if (j > 0 && dp[j - 1] > dp[j]) {
                dp[j] = dp[j - 1];
            }
        }
    }
    printf("%lld\n", dp[V]);
    return 0;
}
