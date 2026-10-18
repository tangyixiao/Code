#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5, M = 1e3 + 5;

int b[N], c[N][N];
double f[N][N][M];

inline void input() {
    int s = 0;
    for (int i = 1; i <= 4; i++) {
        cin >> b[i], s += b[i];
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            c[i][j] = 0;
        }
    }
    if (s == 0) {
        exit(0);
    }
    return;
}

inline void build(int l, int r) {
    if (l == r) {
        c[l][r] = 1, f[l][r][0] = b[l];
        return;
    }
    for (int k = l; k < r; k++) {
        build(l, k);
        build(k + 1, r);
        for (int i = 0; i < c[l][k]; i++) {
            for (int j = 0; j < c[k + 1][r]; j++) {
                double x = f[l][k][i], y = f[k + 1][r][j];
                f[l][r][c[l][r]++] = x + y;
                f[l][r][c[l][r]++] = x - y;
                f[l][r][c[l][r]++] = x * y;
                if (fabs(y) > 1e-9) {
                    f[l][r][c[l][r]++] = x / y;
                }
            }
        }
    }
    return;
}

inline void solve() {
    input();
    build(1, 4);
    for (int i = 0; i < c[1][4]; i++) {
        if (fabs(f[1][4][i] - 24) < 1e-6) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        solve();
    }
    return 0;
}