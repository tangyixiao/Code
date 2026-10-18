#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m;
char a[N][N];

const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = {1, -1, 1, -1, 0, 1, 0, -1};

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] + 1;
    }
    return;
}

inline void dfs(int x, int y) {
    a[x][y] = '.';
    for (int i = 0; i < 8; ++i) {
        int u = x + dx[i], v = y + dy[i];
        if (u < 1 || u > n || v < 1 || v > m || a[u][v] != 'W') {
            continue;
        }
        dfs(u, v);
    }
    return;
}

inline void solve() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'W') {
                ++ans, dfs(i, j);
            }
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
