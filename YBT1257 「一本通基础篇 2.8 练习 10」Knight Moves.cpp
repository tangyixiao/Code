#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

int n, l, sx, sy, ex, ey, d[N][N];
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int qx[N * N], qy[N * N];

signed main() {
    scanf("%d", &n);
    while (n > 0) {
        n--;
        scanf("%d %d %d %d %d", &l, &sx, &sy, &ex, &ey);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                d[i][j] = -1;
            }
        }
        int h = 0, t = 0;
        qx[t] = sx;
        qy[t] = sy;
        t++;
        d[sx][sy] = 0;
        while (h < t) {
            int x = qx[h], y = qy[h];
            h++;
            for (int k = 0; k < 8; k++) {
                int u = x + dx[k], v = y + dy[k];
                if (u < 0 || u >= l || v < 0 || v >= l) {
                    continue;
                }
                if (d[u][v] >= 0) {
                    continue;
                }
                d[u][v] = d[x][y] + 1;
                qx[t] = u;
                qy[t] = v;
                t++;
            }
        }
        printf("%d\n", d[ex][ey]);
    }
    return 0;
}
