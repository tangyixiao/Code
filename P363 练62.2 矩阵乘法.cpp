#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k, a[N][N], b[N][N], c[N][N];

inline void input() {
    cin >> n >> m >> k;
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
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= m; l++) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cout << c[i][j] << (j == k ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}