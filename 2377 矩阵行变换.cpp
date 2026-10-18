#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, a[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    input();
    int k, x, y;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        for (int j = 0; j < m; j++) {
            swap(a[x - 1][j], a[y - 1][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << (j == m - 1 ? "\n" : " ");
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