#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N][N], d[N][N], fx[N][N], fy[N][N];
int qx[105], qy[105];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

signed main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
            d[i][j] = -1;
        }
    }
    int h = 1, t = 1;
    qx[1] = 0;
    qy[1] = 0;
    d[0][0] = 0;
    while (h <= t) {
        int ux = qx[h], uy = qy[h];
        h++;
        for (int k = 0; k < 4; k++) {
            int vx = ux + dx[k], vy = uy + dy[k];
            if (vx < 0 || vx > 4 || vy < 0 || vy > 4) {
                continue;
            }
            if (a[vx][vy] != 0 || d[vx][vy] != -1) {
                continue;
            }
            d[vx][vy] = d[ux][uy] + 1;
            fx[vx][vy] = ux;
            fy[vx][vy] = uy;
            t++;
            qx[t] = vx;
            qy[t] = vy;
        }
    }
    int px[105], py[105], k = 0;
    int cx = 4, cy = 4;
    while (1) {
        px[++k] = cx;
        py[k] = cy;
        if (cx == 0 && cy == 0) {
            break;
        }
        int nx = fx[cx][cy], ny = fy[cx][cy];
        cx = nx;
        cy = ny;
    }
    for (int i = k; i >= 1; i--) {
        cout << "(" << px[i] << ", " << py[i] << ")" << "\n";
    }
    return 0;
}
