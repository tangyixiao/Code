#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, r[N][N], f[N];

inline void input() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            cin >> r[i][j];
        }
    }
}

inline void solve() {
    for (int i = 2; i <= n; ++i) {
        f[i] = 1e9;
        for (int j = 1; j < i; ++j) {
            f[i] = min(f[i], f[j] + r[j][i]);
        }
    }
    cout << f[n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
