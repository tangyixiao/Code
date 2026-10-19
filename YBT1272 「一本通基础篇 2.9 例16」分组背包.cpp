#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5, T = 15;
int v, n, t, w[N], c[N], p[N], f[N], g[N][T];

inline void input() {
    cin >> v >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i] >> p[i];
    }
    return;
}

inline void solve() {
    for (int i = 0; i <= v; i++) {
        f[i] = 0;
    }
    for (int k = 1; k <= t; k++) {
        for (int i = 0; i <= v; i++) {
            g[i][k] = -1;
        }
        for (int j = 1; j <= n; j++) {
            if (p[j] == k) {
                for (int i = v; i >= w[j]; i--) {
                    g[i][k] = max(g[i][k], f[i - w[j]] + c[j]);
                }
            }
        }
        for (int i = 0; i <= v; i++) {
            f[i] = max(f[i], g[i][k]);
        }
    }
    cout << f[v] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}