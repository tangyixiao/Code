#include <bits/stdc++.h>
using namespace std;

const int N = 25 + 5;

int m, n, ex, ey;
char a[N][N];
int d[N][N];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve();

inline void input() {
    while (cin >> m >> n && (m || n)) {
        for (int i = 1; i <= m; ++i) {
            cin >> a[i] + 1;
            for (int j = 1; j <= n; ++j) {
                d[i][j] = -1;
                if (a[i][j] == '@') {
                    ex = i, ey = j;
                }
            }
        }
        memset(d, -1, sizeof d);
        solve();
    }
    return;
}

inline void solve() {
    memset(d, -1, sizeof d);
    queue<pair<int, int>> q;
    q.push({ex, ey}), d[ex][ey] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (u < 1 || u > m || v < 1 || v > n || a[u][v] == '#' || d[u][v] >= 0) {
                continue;
            }
            d[u][v] = d[x][y] + 1;
            q.push({u, v});
        }
    }
    int ans = -1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == '*') {
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
    return 0;
}
