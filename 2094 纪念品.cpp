#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 1e4 + 5;
int t, n, a[N][N], f[M], m;

inline void input() {
    cin >> t >> n >> m;
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    for (int i = 1; i < t; ++i) {
        for (int j = 0; j <= m; ++j) {
            f[j] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] >= a[i + 1][j]) {
                continue;
            }
            for (int k = a[i][j]; k <= m; ++k) {
                f[k] = max(f[k], f[k - a[i][j]] + a[i + 1][j] - a[i][j]);
            }
        }
        m += f[m];
    }
    cout << m << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
