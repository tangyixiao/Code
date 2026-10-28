#include <bits/stdc++.h>
using namespace std;

int m, n;
long long e;
long long c[8];
char g[105][105];

signed main() {
    cin >> m >> n >> e;
    for (int i = 0; i < 8; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = ' ';
        }
    }
    int r = 0, cc = 0, dr = 1, dc = 1;
    for (int step = 0; step < 200005; step++) {
        int nr = r + dr, nc = cc + dc;
        int badr = (nr < 0 || nr > m);
        int badc = (nc < 0 || nc > n);
        if (badr || badc) {
            long long lose;
            if (badr && badc) {
                if (dr > 0 && dc > 0) {
                    lose = c[6];
                } else if (dr > 0 && dc < 0) {
                    lose = c[7];
                } else if (dr < 0 && dc > 0) {
                    lose = c[5];
                } else {
                    lose = c[4];
                }
            } else if (badr) {
                if (dr > 0) {
                    lose = c[2];
                } else {
                    lose = c[0];
                }
            } else {
                if (dc > 0) {
                    lose = c[1];
                } else {
                    lose = c[3];
                }
            }
            e -= lose;
            if (e <= 0) {
                break;
            }
            if (badr) {
                dr = -dr;
            }
            if (badc) {
                dc = -dc;
            }
        } else {
            int x = min(r, nr) + 1, y = min(cc, nc) + 1;
            if (g[x][y] == ' ') {
                if (dr == dc) {
                    g[x][y] = '\\';
                } else {
                    g[x][y] = '/';
                }
            }
            r = nr;
            cc = nc;
        }
    }
    cout << " ";
    for (int i = 1; i <= n; i++) {
        cout << "-";
    }
    cout << " \n";
    for (int i = 1; i <= m; i++) {
        cout << "|";
        for (int j = 1; j <= n; j++) {
            cout << g[i][j];
        }
        cout << "|\n";
    }
    cout << " ";
    for (int i = 1; i <= n; i++) {
        cout << "-";
    }
    cout << " \n";
    return 0;
}
