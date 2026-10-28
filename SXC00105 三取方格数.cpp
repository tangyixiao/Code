#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int a[N][N], f[N][N][N], g[N][N][N];
int n, i, j, s, x1, x2, x3, d1, d2, d3, y1, y2, y3, v, best;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (x1 = 1; x1 <= n; x1++) {
        for (x2 = 1; x2 <= n; x2++) {
            for (x3 = 1; x3 <= n; x3++) {
                f[x1][x2][x3] = -1000000;
            }
        }
    }
    f[1][1][1] = a[1][1];
    for (s = 3; s <= 2 * n; s++) {
        for (x1 = 1; x1 <= n; x1++) {
            for (x2 = 1; x2 <= n; x2++) {
                for (x3 = 1; x3 <= n; x3++) {
                    g[x1][x2][x3] = -1000000;
                }
            }
        }
        for (x1 = 1; x1 <= n; x1++) {
            y1 = s - x1;
            if (y1 < 1 || y1 > n) {
                continue;
            }
            for (x2 = 1; x2 <= n; x2++) {
                y2 = s - x2;
                if (y2 < 1 || y2 > n) {
                    continue;
                }
                for (x3 = 1; x3 <= n; x3++) {
                    y3 = s - x3;
                    if (y3 < 1 || y3 > n) {
                        continue;
                    }
                    best = -1000000;
                    for (d1 = 0; d1 < 2; d1++) {
                        for (d2 = 0; d2 < 2; d2++) {
                            for (d3 = 0; d3 < 2; d3++) {
                                if (x1 - d1 < 1 || x2 - d2 < 1 || x3 - d3 < 1) {
                                    continue;
                                }
                                v = f[x1 - d1][x2 - d2][x3 - d3];
                                if (v > best) {
                                    best = v;
                                }
                            }
                        }
                    }
                    if (best == -1000000) {
                        continue;
                    }
                    v = best + a[x1][y1];
                    if (!(x2 == x1 && y2 == y1)) {
                        v += a[x2][y2];
                    }
                    if (!(x3 == x1 && y3 == y1) && !(x3 == x2 && y3 == y2)) {
                        v += a[x3][y3];
                    }
                    g[x1][x2][x3] = v;
                }
            }
        }
        for (x1 = 1; x1 <= n; x1++) {
            for (x2 = 1; x2 <= n; x2++) {
                for (x3 = 1; x3 <= n; x3++) {
                    f[x1][x2][x3] = g[x1][x2][x3];
                }
            }
        }
    }
    cout << f[n][n][n] << "\n";
    return 0;
}
