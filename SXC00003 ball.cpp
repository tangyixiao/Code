#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int m, n, c[8];
long long e, paid;
char g[N][N];
int seen[N][N][2][2];
long long at[N][N][2][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> e;
    for (int i = 0; i < 8; i++) {
        cin >> c[i];
    }
    for (int i = 0; i <= m + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            g[i][j] = ' ';
        }
    }
    int r = 0, col = 0, dr = 1, dc = 1, one = 0;
    for (;;) {
        int a = (dr < 0), b = (dc < 0);
        if (!one) {
            if (seen[r][col][a][b]) {
                long long cyc = paid - at[r][col][a][b];
                if (cyc <= 0) {
                    break;
                }
                paid += (e - paid - 1) / cyc * cyc, one = 1;
            } else {
                seen[r][col][a][b] = 1, at[r][col][a][b] = paid;
            }
        }
        int top = (r == 0 && dr < 0), bot = (r == m && dr > 0);
        int lef = (col == 0 && dc < 0), rig = (col == n && dc > 0);
        if (top && lef) {
            paid += c[4];
        } else if (top && rig) {
            paid += c[5];
        } else if (bot && rig) {
            paid += c[6];
        } else if (bot && lef) {
            paid += c[7];
        } else if (top) {
            paid += c[0];
        } else if (rig) {
            paid += c[1];
        } else if (bot) {
            paid += c[2];
        } else if (lef) {
            paid += c[3];
        }
        if ((top || bot || lef || rig) && paid >= e) {
            break;
        }
        if (top || bot) {
            dr = -dr;
        }
        if (lef || rig) {
            dc = -dc;
        }
        if (dr > 0 && dc > 0) {
            g[r + 1][col + 1] = '\\';
        } else if (dr > 0 && dc < 0) {
            g[r + 1][col] = '/';
        } else if (dr < 0 && dc < 0) {
            g[r][col] = '\\';
        } else {
            g[r][col + 1] = '/';
        }
        r += dr, col += dc;
    }
    cout << " ";
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << " " << "\n";
    for (int i = 1; i <= m; i++) {
        cout << "|";
        for (int j = 1; j <= n; j++) {
            cout << g[i][j];
        }
        cout << "|" << "\n";
    }
    cout << " ";
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << " " << "\n";
    return 0;
}
