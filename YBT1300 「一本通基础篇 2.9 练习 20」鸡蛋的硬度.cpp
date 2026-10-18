#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 1e2 + 5;
int f[M][M];

inline void input() {}

inline void solve() {
    for (int i = 1; i < M; ++i) {
        for (int j = 1; j < M; ++j) {
            f[i][j] = M;
        }
    }
    for (int i = 1; i < M; ++i) {
        f[i][1] = i;
        f[1][i] = i;
    }
    for (int i = 2; i < M; ++i) {
        for (int j = 2; j < M; ++j) {
            for (int k = 1; k <= i; ++k) {
                f[i][j] = min(f[i][j], max(f[k - 1][j - 1], f[i - k][j]) + 1);
            }
        }
    }
    int n, m;
    for (; cin >> n >> m;) {
        cout << f[n][m] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}