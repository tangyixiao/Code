#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n, m, d, len, fac[N], pr[N], g[N];

inline void input() {
    m = n;
    d = 2, len = 0;
    return;
}

inline void solve() {
    while (d * d <= m) {
        if (m % d == 0) {
            int t = 1;
            while (m % d == 0) {
                m /= d, t *= d;
            }
            fac[len++] = t;
        }
        d++;
    }
    if (m > 1) {
        fac[len++] = m;
    }
    int all = (1 << len) - 1;
    for (int i = 1; i <= all; i++) {
        pr[i] = 1;
        for (int j = 0; j < len; j++) {
            if (i >> j & 1) {
                pr[i] *= fac[j];
            }
        }
        g[i] = pr[i];
        for (int j = (i - 1) & i; j; j = (j - 1) & i) {
            g[i] = min(g[i], pr[j] + g[i ^ j]);
        }
    }
    int ans = pr[all] + 1;
    for (int i = 1; i < all; i++) {
        ans = min(ans, pr[i] + g[all ^ i]);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n && n) {
        input();
        solve();
    }
    return 0;
}