#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

int t, r, c, d[N][N];
char a[N][N];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve();

inline void input() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> r >> c;
        for (int j = 1; j <= r; ++j) {
            cin >> a[j] + 1;
        }
        solve();
    }
    return;
}

inline void solve() {
    memset(d, -1, sizeof d);
    int sx = 0, sy = 0, ex = 0, ey = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (a[i][j] == 'S') {
                sx = i, sy = j;
            } else if (a[i][j] == 'E') {
                ex = i, ey = j;
            }
        }
    }
    queue<pair<int, int>> q;
    d[sx][sy] = 0, q.push({sx, sy});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (u < 1 || u > r || v < 1 || v > c || a[u][v] == '#' || d[u][v] > -1) {
                continue;
            }
            d[u][v] = d[x][y] + 1, q.push({u, v});
        }
    }
    if (d[ex][ey] < 0) {
        cout << "oop!\n";
    } else {
        cout << d[ex][ey] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    return 0;
}
