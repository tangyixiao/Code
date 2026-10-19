#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, x, y;
char a[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x >> y;
    return;
}

inline void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '2') {
        return;
    }
    if (a[i][j] == '0') {
        a[i][j] = '2';
        return;
    }
    a[i][j] = '2';
    for (int u = -1; u <= 1; u++) {
        for (int v = -1; v <= 1; v++) {
            dfs(i + u, j + v);
        }
    }
    return;
}

inline void solve() {
    if (a[x - 1][y - 1] == '1') {
        dfs(x - 1, y - 1);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
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