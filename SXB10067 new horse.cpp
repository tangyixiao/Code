#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int d[N][N], qx[N * N * 20], qy[N * N * 20];
string s, t;
int n, i, j, k;
int dx[12] = {1, 2, 2, 1, -1, -2, -2, -1, 2, 2, -2, -2};
int dy[12] = {2, 1, -1, -2, -2, -1, 1, 2, 2, -2, 2, -2};
int bfs(int sx, int sy) {
    int hd = 0, tl = 0, a, b;
    for (a = 1; a <= 100; a++) {
        for (b = 1; b <= 100; b++) {
            d[a][b] = -1;
        }
    }
    d[sx][sy] = 0, qx[tl] = sx, qy[tl] = sy, tl++;
    while (hd < tl) {
        int x = qx[hd], y = qy[hd];
        hd++;
        if (x == 1 && y == 1) {
            return d[x][y];
        }
        for (k = 0; k < 12; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > 100 || ny < 1 || ny > 100) {
                continue;
            }
            if (d[nx][ny] != -1) {
                continue;
            }
            d[nx][ny] = d[x][y] + 1, qx[tl] = nx, qy[tl] = ny, tl++;
        }
    }
    return -1;
}
signed main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs(x1, y1) << "\n";
    cout << bfs(x2, y2) << "\n";
    return 0;
}
