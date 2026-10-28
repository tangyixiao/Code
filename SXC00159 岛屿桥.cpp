#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;
const int S = 1 << 13;
int n, m, v[N], adj[N][N];
ll f[S][N][N];
int cnt[S][N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, i, j, k, x, y;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
        }
        for (i = 1; i <= m; i++) {
            cin >> x >> y;
            adj[x][y] = 1, adj[y][x] = 1;
        }
        int full = (1 << n) - 1;
        for (i = 0; i <= full; i++) {
            for (j = 1; j <= n; j++) {
                for (k = 1; k <= n; k++) {
                    f[i][j][k] = 0, cnt[i][j][k] = 0;
                }
            }
        }
        for (i = 1; i <= n; i++) {
            f[1 << (i - 1)][i][0] = v[i];
            cnt[1 << (i - 1)][i][0] = 1;
        }
        for (int mask = 1; mask <= full; mask++) {
            for (j = 1; j <= n; j++) {
                if (!(mask >> (j - 1) & 1)) {
                    continue;
                }
                for (k = 0; k <= n; k++) {
                    if (f[mask][j][k] == 0) {
                        continue;
                    }
                    for (x = 1; x <= n; x++) {
                        if (mask >> (x - 1) & 1) {
                            continue;
                        }
                        if (!adj[j][x]) {
                            continue;
                        }
                        ll add = v[x] + (ll)v[j] * v[x];
                        if (k != 0 && adj[k][j] && adj[j][x] && adj[k][x]) {
                            add += (ll)v[k] * v[j] * v[x];
                        }
                        int nm = mask | (1 << (x - 1));
                        if (f[mask][j][k] + add > f[nm][x][j]) {
                            f[nm][x][j] = f[mask][j][k] + add;
                            cnt[nm][x][j] = cnt[mask][j][k];
                        } else if (f[mask][j][k] + add == f[nm][x][j]) {
                            cnt[nm][x][j] += cnt[mask][j][k];
                        }
                    }
                }
            }
        }
        ll best = 0;
        int ways = 0;
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                if (f[full][j][k] > best) {
                    best = f[full][j][k], ways = cnt[full][j][k];
                } else if (f[full][j][k] == best && best > 0) {
                    ways += cnt[full][j][k];
                }
            }
        }
        cout << best << " " << ways / 2 << "\n";
    }
    return 0;
}
