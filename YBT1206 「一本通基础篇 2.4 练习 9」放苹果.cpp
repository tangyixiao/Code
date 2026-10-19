#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int f[N][N], t, m, n;

inline void input() {
    cin >> t;
    for (int i = 0; i <= 1e2; ++i) {
        f[0][i] = 1;
    }
    for (int j = 1; j <= 1e2; ++j) {
        for (int i = 1; i <= 1e2; ++i) {
            f[i][j] = f[i][j - 1];
            if (i >= j) {
                f[i][j] += f[i - j][j];
            }
        }
    }
}

inline void solve() {
    while (t--) {
        cin >> m >> n;
        cout << f[m][n] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
