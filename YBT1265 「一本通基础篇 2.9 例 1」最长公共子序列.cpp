#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, f[N][N];
char x[N], y[N];

inline void input() {
    cin >> x >> y;
    n = strlen(x), m = strlen(y);
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (x[i] == y[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
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