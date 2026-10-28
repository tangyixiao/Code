#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long n, x, s, m, t;

signed main() {
    freopen("wrs.in", "r", stdin);
    freopen("wrs.out", "w", stdout);
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &x);
        s += x;
        t = t + x > 0 ? t + x : 0;
        if (t > m) {
            m = t;
        }
    }
    printf("%lld\n", 2 * m - s);
    return 0;
}
