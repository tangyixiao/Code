#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, m, a[N][N], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, sx, sy, ex, ey;
bool vis[N][N], flag;
inline void dfs(int x, int y, vector<pair<int, int>> path) {
    if (x == ex && y == ey) {
        flag = true;
        int i = 0, siz = path.size();
        for (auto p : path) {
            cout << "(" << p.first << "," << p.second << ")";
            if (i != siz) {
                cout << "->";
            }
            i++;
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny]) {
            vis[nx][ny] = true;
            path.push_back({nx, ny});
            dfs(nx, ny, path);
            path.pop_back();
            vis[nx][ny] = false;
        }
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey;
    dfs(sx, sy, {{sx, sy}});
    if (!flag) {
        cout << -1;
        exit(0);
    }
    return 0;
}