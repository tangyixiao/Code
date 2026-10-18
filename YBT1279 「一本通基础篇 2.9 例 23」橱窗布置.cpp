#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int M = -1e9;
int F, V, a[N][N], f[N][N], b[N];

inline void input() {
    cin >> F >> V;
    for (int i = 1; i <= F; ++i) {
        for (int j = 1; j <= V; ++j) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    for (int j = 0; j <= V; ++j) {
        f[0][j] = 0;
    }
    for (int i = 1; i <= F; ++i) {
        f[i][0] = M;
        for (int j = 1; j <= V; ++j) {
            f[i][j] = max(f[i][j - 1], f[i - 1][j - 1] + a[i][j]);
        }
    }
    cout << f[F][V] << "\n";
    int j = V;
    for (int i = F; i >= 1; --i) {
        for (; f[i][j] != f[i - 1][j - 1] + a[i][j]; --j);
        b[i] = j;
        --j;
    }
    for (int k = 1; k <= F; ++k) {
        cout << b[k] << (k == F ? "\n" : " ");
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}