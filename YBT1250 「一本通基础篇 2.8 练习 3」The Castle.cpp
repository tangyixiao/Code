#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, m, p[N][N], b[N][N], f;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const int w[4] = {2, 1, 4, 8};

inline void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> p[i][j];
        }
    }
    return;
}

inline void dfs(int x, int y) {
    b[x][y] = 1;
    ++f;
    for (int i = 0; i < 4; ++i) {
        int u = x + dx[i], v = y + dy[i];
        if (u < 1 || u > m || v < 1 || v > n || (p[x][y] & w[i])) {
            continue;
        }
        if (b[u][v]) {
            continue;
        }
        dfs(u, v);
    }
    return;
}

inline void solve() {
    int cnt = 0, mx = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (b[i][j]) {
                continue;
            }
            f = 0;
            dfs(i, j);
            ++cnt;
            mx = f > mx ? f : mx;
        }
    }
    cout << cnt << "\n"
         << mx << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
