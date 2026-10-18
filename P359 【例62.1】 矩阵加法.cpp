#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m, a[N][N], b[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] + b[i][j] << (j == m ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}