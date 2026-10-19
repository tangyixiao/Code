#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, x, y;
long long f[N][N];

inline void input() {
    cin >> n >> m >> x >> y;
}

inline void solve() {
    f[x][y] = -1;
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) != 3) {
                continue;
            }
            int p = x + i, q = y + j;
            if (p >= 0 && p <= n && q >= 0 && q <= m) {
                f[p][q] = -1;
            }
        }
    }
    f[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (f[i][j] < 0) {
                f[i][j] = 0;
                continue;
            }
            f[i][j] = (i ? f[i - 1][j] : 0) + (j ? f[i][j - 1] : 0);
        }
    }
    cout << f[n][m] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
