#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, a[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    input();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                cout << i << " " << j << " " << a[i][j] << "\n";
            }
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}