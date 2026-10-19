#include <bits/stdc++.h>
using namespace std;

const int N = 5e1 + 5;
int r, c;
char a[N][N];
int d[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

inline void input() {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        cin >> a[i] + 1;
    }
}

inline void bfs() {
    memset(d, -1, sizeof d);
    int q[N * N], h = 0, t = 0;
    q[t++] = 1;
    d[1][1] = 1;
    for (; h < t; ++h) {
        int x = (q[h] - 1) / c + 1, y = (q[h] - 1) % c + 1;
        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (u >= 1 && u <= r && v >= 1 && v <= c && a[u][v] == '.' && d[u][v] < 0) {
                d[u][v] = d[x][y] + 1;
                q[t++] = (u - 1) * c + v;
            }
        }
    }
}

inline void solve() {
    bfs();
    cout << d[r][c] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}