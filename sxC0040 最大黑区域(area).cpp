#include <bits/stdc++.h>
using namespace std;

int n, m, i, j, best, cur;
int a[105][105], v[105][105];
int qx[10005], qy[10005];

void bfs(int sx, int sy) {
    int h = 0, t = 0;
    qx[t] = sx;
    qy[t] = sy;
    t++;
    v[sx][sy] = 1;
    cur = 0;
    while (h < t) {
        int x = qx[h], y = qy[h];
        h++;
        cur++;
        for (int k = 0; k < 4; k++) {
            int nx = x + (k == 0 ? -1 : (k == 1 ? 1 : 0));
            int ny = y + (k == 2 ? -1 : (k == 3 ? 1 : 0));
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == 1 && v[nx][ny] == 0) {
                v[nx][ny] = 1;
                qx[t] = nx;
                qy[t] = ny;
                t++;
            }
        }
    }
    if (cur > best) {
        best = cur;
    }
}

signed main() {
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    best = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i][j] == 1 && v[i][j] == 0) {
                bfs(i, j);
            }
        }
    }
    cout << best << "\n";
    return 0;
}
