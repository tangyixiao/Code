#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, a[N][N], b[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            b[i][j] = i == 1 || j == 1 || i == n || j == m
                          ? a[i][j]
                          : (a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1]) / 5;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << b[i][j] << (j == m ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}