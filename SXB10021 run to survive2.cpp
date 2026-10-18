#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int L, R, C, hd, tp, i, j, k, x, y, z, d;
char a[N][N][N], s[N];
struct node {
    int x, y, z, d;
} q[N * N * N];
int dx[6] = {1, -1, 0, 0, 0, 0}, dy[6] = {0, 0, 1, -1, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};

signed main() {
    cin >> L >> R >> C;
    for (i = 0; i < L; i++) {
        for (j = 0; j < R; j++) {
            scanf("%s", s);
            for (k = 0; k < C; k++) {
                a[i][j][k] = s[k];
            }
        }
    }
    for (i = 0; i < L; i++) {
        for (j = 0; j < R; j++) {
            for (k = 0; k < C; k++) {
                if (a[i][j][k] == 'S') {
                    x = i, y = j, z = k, d = 0, a[i][j][k] = '*';
                }
            }
        }
    }
    hd = 0, tp = 1;
    q[tp] = {x, y, z, d};
    while (hd < tp) {
        node t = q[++hd];
        for (i = 0; i < 6; i++) {
            int u = t.x + dx[i], v = t.y + dy[i], w = t.z + dz[i];
            if (u < 0 || u >= L || v < 0 || v >= R || w < 0 || w >= C) {
                continue;
            }
            if (a[u][v][w] == '#' || a[u][v][w] == '*') {
                continue;
            }
            if (a[u][v][w] == 'E') {
                cout << t.d + 1 << "\n";
                return 0;
            }
            a[u][v][w] = '*';
            q[++tp] = {u, v, w, t.d + 1};
        }
    }
    cout << "Trapped!\n";
    return 0;
}