#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, a[N][N], b[N][N];

inline void input() { cin >> n >> m; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = n; i >= 1; --i) {
            b[j][n - i + 1] = a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << b[i][j] << (j == n ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}