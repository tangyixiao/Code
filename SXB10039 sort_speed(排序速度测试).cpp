#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
const long long MOD = 998244353;
int a[N];
int n, x, y;

signed main() {
    if (fopen("sort_speed.in", "r")) {
        freopen("sort_speed.in", "r", stdin);
        freopen("sort_speed.out", "w", stdout);
    }
    scanf("%d%d%d", &n, &x, &y);
    long long cur = 1;
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cur = ((cur * x + y) % MOD + MOD) % MOD;
        }
        a[i] = (int)cur;
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            ans += a[i];
        } else {
            ans -= a[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
