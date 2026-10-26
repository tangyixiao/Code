#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, a[N][N], f[N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    if (f[x][y]) {
        return f[x][y];
    }
    f[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] < a[x][y]) {
            f[x][y] = max(f[x][y], 1 + dfs(nx, ny));
        }
    }
    return f[x][y];
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << "\n";
    return 0;
}
