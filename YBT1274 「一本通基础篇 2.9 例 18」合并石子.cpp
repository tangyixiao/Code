#include <bits/stdc++.h>
using namespace std;

const int N = 5e1 + 5;
int n, a[N], s[N], f[N][N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = 1e9;
        }
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        f[i][i] = 0;
    }
    for (int j = 2; j <= n; ++j) {
        for (int i = 1; i + j - 1 <= n; ++i) {
            int r = i + j - 1;
            for (int k = i; k < r; ++k) {
                f[i][r] = min(f[i][r], f[i][k] + f[k + 1][r] + s[r] - s[i - 1]);
            }
        }
    }
    cout << f[1][n] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}