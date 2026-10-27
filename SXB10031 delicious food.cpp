#include <bits/stdc++.h>
using namespace std;
const int N = 45;
const int M = 305;
int n, L, R, i, j, v[N], s;
long long dp[M], ans;
signed main() {
    if (fopen("food.in", "r")) {
        freopen("food.in", "r", stdin);
        freopen("food.out", "w", stdout);
    }
    scanf("%d%d%d", &n, &L, &R);
    dp[0] = 1;
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        for (j = R; j >= v[i]; j--) {
            dp[j] += dp[j - v[i]];
        }
    }
    for (j = L; j <= R; j++) {
        ans += dp[j];
    }
    printf("%lld\n", ans);
    return 0;
}
