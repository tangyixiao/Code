#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int m, n, a[N][N], b[N][N];

inline void input() {
    cin >> m >> n;
    return;
}

inline void solve() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] = a[i][j];
        }
    }
    for (int i = 2; i < m; i++) {
        for (int j = 2; j < n; j++) {
            int s = a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
            b[i][j] = (s + 2) / 5;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << b[i][j] << " \n"[j == n];
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}