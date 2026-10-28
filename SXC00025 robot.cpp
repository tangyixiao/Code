#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int INF = 1e9;
int m, n, cy, cx, fy, fx;
char g[N][N];
int nxt[N][N], cur[N][N], yv[N * N], fv[N * N];
int dx[26], dy[26];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j, d, len, ni, nj, best;
    string s;
    dx['N' - 'A'] = -1, dy['N' - 'A'] = 0;
    dx['S' - 'A'] = 1, dy['S' - 'A'] = 0;
    dx['E' - 'A'] = 0, dy['E' - 'A'] = 1;
    dx['W' - 'A'] = 0, dy['W' - 'A'] = -1;
    cin >> m >> n;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'Y') {
                cy = i, cx = j;
            }
            if (g[i][j] == 'F') {
                fy = i, fx = j;
            }
        }
    }
    cin >> s;
    len = s.size();
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            nxt[i][j] = (g[i][j] == 'X' || g[i][j] == '#') ? (g[i][j] == 'X' ? 0 : INF) : INF;
        }
    }
    for (d = len - 1; d >= 0; d--) {
        int ax = dx[s[d] - 'A'], ay = dy[s[d] - 'A'];
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (g[i][j] == 'X') {
                    cur[i][j] = 0;
                    continue;
                }
                if (g[i][j] == '#') {
                    cur[i][j] = INF;
                    continue;
                }
                best = nxt[i][j];
                ni = i + ax, nj = j + ay;
                if (ni >= 1 && ni <= m && nj >= 1 && nj <= n && g[ni][nj] != '#' && nxt[ni][nj] < best) {
                    best = nxt[ni][nj];
                }
                cur[i][j] = best >= INF ? INF : best + 1;
            }
        }
        yv[d] = cur[cy][cx];
        fv[d] = cur[fy][fx];
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                nxt[i][j] = cur[i][j];
            }
        }
    }
    yv[len] = nxt[cy][cx], fv[len] = nxt[fy][fx];
    int ans = -1;
    for (d = 0; d <= len; d++) {
        if (yv[d] < fv[d]) {
            ans = d;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
