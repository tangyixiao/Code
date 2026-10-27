#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, m, i, j, sx, sy, tx, ty, hd, tl;
char g[N][N];
int d[N][N], qx[N * N], qy[N * N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
signed main() {
    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 && m == 0) {
            break;
        }
        for (i = 0; i < n; i++) {
            scanf("%s", g[i]);
            for (j = 0; j < m; j++) {
                if (g[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
                if (g[i][j] == '*') {
                    tx = i;
                    ty = j;
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                d[i][j] = -1;
            }
        }
        hd = 0;
        tl = 0;
        d[sx][sy] = 0;
        qx[tl] = sx;
        qy[tl] = sy;
        tl++;
        while (hd < tl) {
            int cx = qx[hd], cy = qy[hd];
            hd++;
            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k], ny = cy + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (g[nx][ny] == '#' || d[nx][ny] >= 0) {
                    continue;
                }
                d[nx][ny] = d[cx][cy] + 1;
                qx[tl] = nx;
                qy[tl] = ny;
                tl++;
            }
        }
        if (d[tx][ty] < 0) {
            printf("-1\n");
        } else {
            printf("%d\n", d[tx][ty]);
        }
    }
    return 0;
}
