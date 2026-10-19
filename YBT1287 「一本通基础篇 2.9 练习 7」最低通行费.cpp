#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 1e9;
int n, a[N][N], f[N][N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void solve() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = M;
        }
    }
    f[1][1] = a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            f[i][j] = a[i][j] + min(f[i - 1][j], f[i][j - 1]);
        }
    }
    cout << f[n][n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
