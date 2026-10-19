#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int m, n, k;
int f[25][85], g[25][85];

inline void input() {
    cin >> m >> n >> k;
    return;
}

inline void solve() {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = 0x3f3f3f3f;
        }
    }
    f[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        memcpy(g, f, sizeof(f));
        for (int o = 0; o <= m; o++) {
            for (int q = 0; q <= n; q++) {
                if (f[o][q] < 0x3f3f3f3f) {
                    int p = min(m, o + a), t = min(n, q + b);
                    g[p][t] = min(g[p][t], f[o][q] + c);
                }
            }
        }
        memcpy(f, g, sizeof(f));
    }
    cout << f[m][n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}