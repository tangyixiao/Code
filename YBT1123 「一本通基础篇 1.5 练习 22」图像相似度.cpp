#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int m, n, a[N][N], s;

inline void input() {
    cin >> m >> n;
    return;
}

inline void solve() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int b;
            cin >> b;
            if (b == a[i][j]) {
                s++;
            }
        }
    }
    cout << fixed << setprecision(2) << 100.0 * s / (m * n) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}