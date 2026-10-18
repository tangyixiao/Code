#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int m, n, a[N][N];
long long s;

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
            if (i == 1 || i == m || j == 1 || j == n) {
                s += a[i][j];
            }
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}