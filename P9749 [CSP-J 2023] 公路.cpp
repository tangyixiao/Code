#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
inline int __ceil(double parameter) { return (int)(parameter + 0.5); }
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
int n, d, v[N], a[N], mi = inf, ans, vis, sum, t;

signed main() {
    scanf("%lld %lld", &n, &d);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        mi = min(mi, a[i]);
        if (sum >= v[i]) {
            sum -= v[i];
            continue;
        }
        t = (v[i] - sum + d - 1) / d;
        ans += 1ll * t * mi;
        sum = t * d + sum - v[i];
    }
    printf("%lld", ans);
    return 0;
}