#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int M = 1e3 + 5;
int a[N][M], px[N * M], py[N * M], n, m, i, j;
int check(int lim) {
    int hd = 0, tl = 0, x, y, k;
    static int vis[N][M];
    static int sx[N * M], sy[N * M];
    for (x = 1; x <= n; x++) {
        for (y = 1; y <= m; y++) {
            vis[x][y] = 0;
        }
    }
    for (y = 1; y <= m; y++) {
        if (a[1][y] <= lim && vis[1][y] == 0) {
            vis[1][y] = 1, sx[tl] = 1, sy[tl] = y, tl++;
        }
    }
    while (hd < tl) {
        x = sx[hd], y = sy[hd], hd++;
        if (x == n) {
            return 1;
        }
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        for (k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (vis[nx][ny] == 1 || a[nx][ny] > lim) {
                continue;
            }
            vis[nx][ny] = 1, sx[tl] = nx, sy[tl] = ny, tl++;
        }
    }
    return 0;
}
signed main() {
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int lo = 0, hi = 1000, ans = 1000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid) == 1) {
            ans = mid, hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
