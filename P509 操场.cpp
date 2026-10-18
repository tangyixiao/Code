#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N][N];
bool vis[N][N];

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

inline void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if (u < 1 || u > n || v < 1 || v > n || vis[u][v] || a[u][v]) {
            continue;
        }
        dfs(u, v);
    }
    return;
}

inline void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j] && !vis[i][j]) {
                ans++, dfs(i, j);
            }
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
