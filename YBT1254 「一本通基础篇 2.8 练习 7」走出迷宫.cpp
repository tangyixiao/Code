#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, d[N][N];
char a[N][N];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] + 1;
    }
    return;
}

inline void solve() {
    queue<pair<int, int>> q;
    int sx = 0, sy = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] = -1;
            if (a[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    d[sx][sy] = 0, q.push({sx, sy});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (u < 1 || u > n || v < 1 || v > m || a[u][v] == '#' || d[u][v] > -1) {
                continue;
            }
            d[u][v] = d[x][y] + 1, q.push({u, v});
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'T') {
                ans = d[i][j];
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
