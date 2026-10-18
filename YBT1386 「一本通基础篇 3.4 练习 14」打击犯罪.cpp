#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, g[N][N], q[N], f[N];

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        int c, v;
        cin >> c;
        while (c--) {
            cin >> v;
            g[i][v] = g[v][i] = 1;
        }
    }
    for (int k = 0; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            f[i] = 0;
        }
        int mx = 0;
        for (int i = k + 1; i <= n; ++i) {
            if (f[i]) {
                continue;
            }
            int hh = 0, tt = 0, cnt = 0;
            q[tt++] = i, f[i] = 1;
            while (hh < tt) {
                int u = q[hh++];
                ++cnt;
                for (int v = k + 1; v <= n; ++v) {
                    if (g[u][v] && !f[v]) {
                        f[v] = 1, q[tt++] = v;
                    }
                }
            }
            mx = max(mx, cnt);
        }
        if (mx * 2 <= n) {
            cout << k << "\n";
            return;
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}