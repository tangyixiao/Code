#include <bits/stdc++.h>
using namespace std;

const int N = 205, M = 35;
int v, n, t, a[N], b[N], g[N], f[N], h[N];

inline void input() {
    cin >> v >> n >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> g[i];
    }
}

inline void solve() {
    for (int j = 0; j <= v; ++j) {
        f[j] = 0;
    }
    for (int k = 1; k <= t; ++k) {
        for (int j = 0; j <= v; ++j) {
            h[j] = f[j];
        }
        for (int i = 1; i <= n; ++i) {
            if (g[i] != k) {
                continue;
            }
            for (int j = v; j >= a[i]; --j) {
                h[j] = max(h[j], f[j - a[i]] + b[i]);
            }
        }
        for (int j = 0; j <= v; ++j) {
            f[j] = h[j];
        }
    }
    cout << f[v] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
