#include <bits/stdc++.h>
using namespace std;

const int N = 8e2 + 5;
int n, m;
char a[N][N];
bool vis[N][N];

const int dx[] = {0, 0, 1, 1, -1, -1, 1, -1}, dy[] = {1, -1, 0, 1, 0, -1, -1, 1};

inline void input() {
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ch, a[i][j] = ch;
        }
    }
}

inline int dfs(int x, int y) {
    vis[x][y] = 1;
    int s = 1;
    for (int i = 0; i < 8; i++) {
        int u = x + dx[i], v = y + dy[i];
        if (u < 1 || u > m || v < 1 || v > n || vis[u][v] || a[u][v] != '.') {
            continue;
        }
        s += dfs(u, v);
    }
    return s;
}

inline void solve() {
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                ans = max(ans, dfs(i, j));
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
