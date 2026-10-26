#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m, ans;
char g[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void dfs(int x, int y) {
    g[x][y] = '0';
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && g[nx][ny] != '0') {
            dfs(nx, ny);
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] != '0') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
