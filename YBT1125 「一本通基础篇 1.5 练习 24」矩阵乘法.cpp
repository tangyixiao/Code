#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, k, a[N][N], b[N][N], c[N][N];

inline void input() {
    cin >> n >> m >> k;
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int t = 1; t <= m; t++) {
                c[i][j] += a[i][t] * b[t][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cout << c[i][j] << " \n"[j == k];
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}