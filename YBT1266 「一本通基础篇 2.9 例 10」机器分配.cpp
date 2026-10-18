#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, m, v[N][N], f[N][N], g[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = -1e9;
            for (int k = 0; k <= j; k++) {
                if (f[i-1][j-k] + v[i][k] > f[i][j]) {
                    f[i][j] = f[i-1][j-k] + v[i][k], g[i][j] = k;
                }
            }
        }
    }
    cout << f[n][m] << "\n";
    int t = m;
    int r[N];
    for (int i = n; i >= 1; i--) {
        r[i] = g[i][t], t -= g[i][t];
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " " << r[i] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
