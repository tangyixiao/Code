#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5, M = 1e9 + 5;
int m, b[N][N], d[N][N];

const int dx[] = {1, -1, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0};

inline void input() {
    cin >> m;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i][j] = M, d[i][j] = -1;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        for (int j = 0; j < 5; j++) {
            int u = x + dx[j], v = y + dy[j];
            if (u >= 0 && u < N && v >= 0 && v < N && t < b[u][v]) {
                b[u][v] = t;
            }
        }
    }
}

inline void solve() {
    if (b[0][0] == 0) {
        cout << "-1\n";
        return;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0)), d[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (b[x][y] == M) {
            cout << d[x][y] << "\n";
            return;
        }
        for (int i = 0; i < 4; i++) {
            int u = x + dx[i], v = y + dy[i];
            if (u < 0 || u >= N || v < 0 || v >= N || d[u][v] >= 0 || d[x][y] + 1 >= b[u][v]) {
                continue;
            }
            d[u][v] = d[x][y] + 1, q.push(make_pair(u, v));
        }
    }
    cout << "-1\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
