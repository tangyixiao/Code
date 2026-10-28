#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int g[N][N], d[2 * N * N * 4], q[2 * N * N * 4];
int n, m;
int dr[4] = {0, -1, 1, 0};
int dc[4] = {1, 0, 0, -1};
int lf[4] = {1, 0, 2, 3}, rt[4] = {2, 1, 3, 0};

bool freecell(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) {
        return false;
    }
    return g[r][c] == 0;
}

bool okp(int r, int c) {
    return freecell(r - 1, c - 1) && freecell(r - 1, c) && freecell(r, c - 1) && freecell(r, c);
}

int enc(int r, int c, int dir) {
    return ((r * (m + 1) + c) * 4) + dir;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int sx, sy, fx, fy;
    char ch;
    cin >> sx >> sy >> fx >> fy >> ch;
    int sd = 0;
    if (ch == 'E') {
        sd = 0;
    }
    if (ch == 'N') {
        sd = 1;
    }
    if (ch == 'S') {
        sd = 2;
    }
    if (ch == 'W') {
        sd = 3;
    }
    int tot = (n + 1) * (m + 1) * 4;
    for (int i = 0; i < tot; i++) {
        d[i] = -1;
    }
    int h = 0, t = 0;
    int st = enc(sx, sy, sd);
    d[st] = 0;
    q[t++] = st;
    while (h < t) {
        int u = q[h++];
        int dir = u % 4, rc = u / 4, c = rc % (m + 1), r = rc / (m + 1);
        int nd = d[u] + 1;
        int a = enc(r, c, lf[dir]);
        if (d[a] < 0) {
            d[a] = nd;
            q[t++] = a;
        }
        int b = enc(r, c, rt[dir]);
        if (d[b] < 0) {
            d[b] = nd;
            q[t++] = b;
        }
        for (int k = 1; k <= 3; k++) {
            int nr = r + dr[dir] * k, nc = c + dc[dir] * k;
            if (nr < 0 || nr > n || nc < 0 || nc > m || !okp(nr, nc)) {
                break;
            }
            int nx = enc(nr, nc, dir);
            if (d[nx] < 0) {
                d[nx] = nd;
                q[t++] = nx;
            }
        }
    }
    int best = -1;
    for (int k = 0; k < 4; k++) {
        int v = d[enc(fx, fy, k)];
        if (v >= 0 && (best < 0 || v < best)) {
            best = v;
        }
    }
    cout << best << "\n";
    return 0;
}
