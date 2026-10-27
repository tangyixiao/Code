#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5, INF = 1e9;
int n, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int des[N][N], dis[N][N];
int qx[N * N], qy[N * N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            des[i][j] = INF;
            dis[i][j] = -1;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        des[x][y] = min(des[x][y], t);
        if (x > 0) {
            des[x - 1][y] = min(des[x - 1][y], t);
        }
        if (y > 0) {
            des[x][y - 1] = min(des[x][y - 1], t);
        }
        des[x + 1][y] = min(des[x + 1][y], t);
        des[x][y + 1] = min(des[x][y + 1], t);
    }
    int h = 1, tl = 0, ans = -1;
    qx[0] = 0, qy[0] = 0, dis[0][0] = 0;
    for (; tl < h;) {
        int x = qx[tl], y = qy[tl], d = dis[x][y];
        tl++;
        if (des[x][y] == INF) {
            ans = d;
            break;
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                continue;
            }
            if (dis[nx][ny] != -1 || des[nx][ny] <= d + 1) {
                continue;
            }
            dis[nx][ny] = d + 1;
            qx[h] = nx, qy[h] = ny, h++;
        }
    }
    cout << ans << "\n";
    return 0;
}
