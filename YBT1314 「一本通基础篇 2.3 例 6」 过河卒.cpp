#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, m, a, b;
long long f[N][N];
bool g[N][N];
int tx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ty[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

inline void input() {
    cin >> n >> m >> a >> b;
    return;
}

inline void solve() {
    if (a >= 0 && a <= n && b >= 0 && b <= m) {
        g[a][b] = true;
    }
    for (int i = 0; i < 8; i++) {
        int x = a + tx[i], y = b + ty[i];
        if (x >= 0 && x <= n && y >= 0 && y <= m) {
            g[x][y] = true;
        }
    }
    f[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (g[i][j]) {
                continue;
            }
            if (i > 0) {
                f[i][j] += f[i - 1][j];
            }
            if (j > 0) {
                f[i][j] += f[i][j - 1];
            }
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