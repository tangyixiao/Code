#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n, a[N][N], f[N][N][N][N];

inline void input() {
    cin >> n;
    while (true) {
        int x, y, z;
        cin >> x;
        if (x == 0) {
            break;
        }
        cin >> y >> z;
        a[x][y] = z;
    }
}

inline void solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                for (int l = 0; l < N; ++l) {
                    f[i][j][k][l] = -1e9;
                }
            }
        }
    }
    f[1][1][1][1] = a[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                for (int l = 1; l <= n; ++l) {
                    int mx = max(max(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1]), max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]));
                    if (mx < -1e8) {
                        continue;
                    }
                    f[i][j][k][l] = mx + a[i][j] + ((i == k && j == l) ? 0 : a[k][l]);
                }
            }
        }
    }
    cout << f[n][n][n][n] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
