#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
int d[N][N], qx[N * N], qy[N * N], n, m, a, b, i, j;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> a >> b;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            d[i][j] = -1;
        }
    }
    int hd = 0, tl = 0;
    for (i = 1; i <= a; i++) {
        int x, y;
        cin >> x >> y;
        if (d[x][y] == -1) {
            d[x][y] = 0, qx[tl] = x, qy[tl] = y, tl++;
        }
    }
    while (hd < tl) {
        int x = qx[hd], y = qy[hd];
        hd++;
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (d[nx][ny] != -1) {
                continue;
            }
            d[nx][ny] = d[x][y] + 1, qx[tl] = nx, qy[tl] = ny, tl++;
        }
    }
    for (i = 1; i <= b; i++) {
        int x, y;
        cin >> x >> y;
        cout << d[x][y] << "\n";
    }
    return 0;
}
