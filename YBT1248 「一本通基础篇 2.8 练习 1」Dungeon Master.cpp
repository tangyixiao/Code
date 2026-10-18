#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int L, R, C;
char g[N][N][N];
int d[N][N][N];
int qx[N * N * N], qy[N * N * N], qz[N * N * N];
int hh, tt;

inline void input() {
    cin >> L >> R >> C;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < R; ++j) {
            cin >> g[i][j];
        }
    }
}

const int dx[6] = {0, 0, 0, 0, 1, -1};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {1, -1, 0, 0, 0, 0};

inline void solve() {
    int sx = 0, sy = 0, sz = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < R; ++j) {
            for (int k = 0; k < C; ++k) {
                d[i][j][k] = -1;
                if (g[i][j][k] == 'S') {
                    sx = i, sy = j, sz = k;
                }
            }
        }
    }
    d[sx][sy][sz] = 0, qx[tt] = sx, qy[tt] = sy, qz[tt] = sz, ++tt;
    while (hh < tt) {
        int x = qx[hh], y = qy[hh], z = qz[hh];
        ++hh;
        if (g[x][y][z] == 'E') {
            cout << d[x][y][z] << "\n";
            return;
        }
        for (int i = 0; i < 6; ++i) {
            int a = x + dx[i], b = y + dy[i], c = z + dz[i];
            if (a < 0 || a >= L || b < 0 || b >= R || c < 0 || c >= C) {
                continue;
            }
            if (d[a][b][c] != -1 || g[a][b][c] == '#') {
                continue;
            }
            d[a][b][c] = d[x][y][z] + 1, qx[tt] = a, qy[tt] = b, qz[tt] = c, ++tt;
        }
    }
    cout << -1 << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
