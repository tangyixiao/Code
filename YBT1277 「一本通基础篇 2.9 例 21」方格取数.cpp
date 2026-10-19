#include <bits/stdc++.h>
using namespace std;

const int N = 25, M = 12;
int n, a[N][N], f[N][M][M];

inline void input() {
    cin >> n;
    int x, y, v;
    while (cin >> x >> y >> v) {
        a[x][y] = v;
    }
    return;
}

inline void solve() {
    for (int t = 1; t <= 2 * n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[t][i][j] = -1;
            }
        }
    }
    f[1][1][1] = a[1][1];
    for (int t = 2; t <= 2 * n; t++) {
        for (int i = t - 1 > n ? n : t - 1; i >= 1; i--) {
            for (int j = t - 1 > n ? n : t - 1; j >= 1; j--) {
                int c1 = t - i, c2 = t - j;
                if (c1 > n || c2 > n || c1 < 1 || c2 < 1) {
                    continue;
                }
                int u = max(f[t - 1][i][j], f[t - 1][i - 1][j]);
                u = max(u, f[t - 1][i][j - 1]);
                u = max(u, f[t - 1][i - 1][j - 1]);
                if (u < 0) {
                    continue;
                }
                if (i == j) {
                    f[t][i][j] = u + a[i][c1];
                } else {
                    f[t][i][j] = u + a[i][c1] + a[j][c2];
                }
            }
        }
    }
    cout << f[2 * n][n][n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
