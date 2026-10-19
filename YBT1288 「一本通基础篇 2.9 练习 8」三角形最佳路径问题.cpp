#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int h, a[N][N], f[N][N];

inline void input() {
    cin >> h;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 1) {
                f[i][j] = a[i][j];
            } else if (j == 1) {
                f[i][j] = f[i - 1][j] + a[i][j];
            } else {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
            }
        }
    }
    int t = 0;
    for (int j = 1; j <= h; j++) {
        t = max(t, f[h][j]);
    }
    cout << t << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}