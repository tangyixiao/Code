#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int d[N][N];
int mx[12] = {1, 2, -1, -2, 1, 2, -1, -2, 2, 2, -2, -2};
int my[12] = {2, 1, 2, 1, -2, -1, -2, -1, 2, -2, 2, -2};
int qx[N * N * 4], qy[N * N * 4];
int bfs(int tx, int ty) {
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= N - 1; j++) {
            d[i][j] = -1;
        }
    }
    int h = 0, t = 0;
    d[1][1] = 0;
    qx[t] = 1;
    qy[t] = 1;
    t++;
    for (; h < t;) {
        int x = qx[h], y = qy[h];
        h++;
        if (x == tx && y == ty) {
            return d[x][y];
        }
        for (int k = 0; k < 12; k++) {
            int nx = x + mx[k], ny = y + my[k];
            if (nx >= 1 && nx <= 100 && ny >= 1 && ny <= 100 && d[nx][ny] < 0) {
                d[nx][ny] = d[x][y] + 1;
                qx[t] = nx;
                qy[t] = ny;
                t++;
            }
        }
    }
    return -1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, e;
    cin >> a >> b >> c >> e;
    cout << bfs(a, b) << "\n";
    cout << bfs(c, e) << "\n";
    return 0;
}
