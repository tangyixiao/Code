#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, ans, dp[N], a[N][26], to[N];
char s[N];
signed main() {
    scanf("%lld%s", &n, s + 1);
    for (int i = 1; i <= n; i++) {
        to[i] = i;
        int x = a[to[i - 1]][s[i] - 'a'];
        if (x) {
            to[i] = to[x - 1];
            dp[i] = dp[x - 1] + 1;
        }
        a[to[i]][s[i] - 'a'] = i;
        ans += dp[i];
    }
    printf("%lld\n", ans);
    return 0;
}