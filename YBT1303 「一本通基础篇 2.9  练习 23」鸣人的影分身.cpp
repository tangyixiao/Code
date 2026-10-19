#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int f[N][N];

inline void input() {
    for (int i = 0; i < N; i++) {
        f[0][i] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            f[i][j] = f[i][j - 1] + (i >= j ? f[i - j][j] : 0);
        }
    }
}

inline void solve() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        cout << f[m][n] << "\n";
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