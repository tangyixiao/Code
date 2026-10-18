#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, a[N][N], b[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][n - 1 - i] = a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << (j + 1 == n ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}