#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m;
bool g[N][N], f[N][N];

inline void input() { cin >> n >> m; }

inline void solve() {
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = g[i][j];
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (f[i][k] && f[k][j]) {
                    f[i][j] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int a = 0, b = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            a += f[j][i], b += f[i][j];
        }
        if (a >= (n + 1) / 2 || b >= (n + 1) / 2) {
            ans++;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}