#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 5;
int n, m, ks, vs;
char g[N][N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'k') {
                ks++;
            }
            if (g[i][j] == 'v') {
                vs++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '#') {
                continue;
            }
            int k = 0, v = 0, edge = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            if (g[i][j] == 'k') {
                k++;
            }
            if (g[i][j] == 'v') {
                v++;
            }
            g[i][j] = '#';
            for (; !q.empty();) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if (x == 1 || x == n || y == 1 || y == m) {
                    edge = 1;
                }
                for (int t = 0; t < 4; t++) {
                    int nx = x + dx[t], ny = y + dy[t];
                    if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '#') {
                        continue;
                    }
                    if (g[nx][ny] == 'k') {
                        k++;
                    }
                    if (g[nx][ny] == 'v') {
                        v++;
                    }
                    g[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
            if (edge) {
                continue;
            }
            if (k > v) {
                vs -= v;
            } else {
                ks -= k;
            }
        }
    }
    cout << ks << " " << vs << "\n";
    return 0;
}
