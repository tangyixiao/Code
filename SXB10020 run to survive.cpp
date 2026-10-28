#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n, sx, sy, fx, fy, d[N][N];
char g[N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    cin >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = -1;
        }
    }
    int qx[N * N], qy[N * N], h = 0, t = 0;
    qx[t] = sx, qy[t] = sy, t++;
    d[sx][sy] = 0;
    for (; h < t;) {
        int x = qx[h], y = qy[h];
        h++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n) {
                continue;
            }
            if (g[nx][ny] == '#' || d[nx][ny] != -1) {
                continue;
            }
            d[nx][ny] = d[x][y] + 1;
            qx[t] = nx, qy[t] = ny, t++;
        }
    }
    cout << d[fx][fy] << "\n";
    return 0;
}
