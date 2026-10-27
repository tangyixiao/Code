#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int n, i, j, k, cx, cy;
int mt[N][N], d[N][N];
int qx[N * N * 4], qy[N * N * 4];
int dx[5] = {1, -1, 0, 0, 0};
int dy[5] = {0, 0, 1, -1, 0};

signed main() {
    if (fopen("meteor.in", "r")) {
        freopen("meteor.in", "r", stdin);
        freopen("meteor.out", "w", stdout);
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            mt[i][j] = 1e9;
            d[i][j] = -1;
        }
    }
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        if (x < 0 || y < 0 || x >= N || y >= N) {
            continue;
        }
        for (k = 0; k < 5; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (t < mt[nx][ny]) {
                    mt[nx][ny] = t;
                }
            }
        }
    }
    int head = 0, tail = 0;
    if (mt[0][0] > 0) {
        qx[tail] = 0;
        qy[tail] = 0;
        tail++;
        d[0][0] = 0;
    }
    int ans = -1;
    while (head < tail) {
        cx = qx[head];
        cy = qy[head];
        head++;
        if (mt[cx][cy] >= 1e9) {
            ans = d[cx][cy];
            break;
        }
        for (k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                continue;
            }
            if (d[nx][ny] != -1) {
                continue;
            }
            if (d[cx][cy] + 1 < mt[nx][ny]) {
                d[nx][ny] = d[cx][cy] + 1;
                qx[tail] = nx;
                qy[tail] = ny;
                tail++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
