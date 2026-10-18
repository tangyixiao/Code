#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, a[N][N];
bool vis[N][N];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

inline void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if (u >= 1 && u <= n && v >= 1 && v <= m && a[u][v] == 1 && !vis[u][v]) {
            dfs(u, v);
        }
    }
    return;
}

inline void solve() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1 && !vis[i][j]) {
                cnt++, dfs(i, j);
            }
        }
    }
    cout << cnt << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
