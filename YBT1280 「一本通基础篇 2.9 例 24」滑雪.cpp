#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int r, c, a[N][N], f[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

inline void input() {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> a[i][j];
        }
    }
}

inline int dfs(int x, int y) {
    if (f[x][y]) {
        return f[x][y];
    }
    f[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int u = x + dx[i], v = y + dy[i];
        if (u >= 1 && u <= r && v >= 1 && v <= c && a[u][v] < a[x][y]) {
            f[x][y] = max(f[x][y], dfs(u, v) + 1);
        }
    }
    return f[x][y];
}

inline void solve() {
    int s = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            s = max(s, dfs(i, j));
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