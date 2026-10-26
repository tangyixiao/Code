#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, d[N][N];

signed main() {
    int i, j, k, u, v, w, a, b, c;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            d[i][j] = 1e9;
        }
        d[i][i] = 0;
    }
    for (i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    cin >> a >> b >> c;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int ans = 1e9;
    for (i = 1; i <= n; i++) {
        ans = min(ans, d[a][i] + d[b][i] + d[c][i]);
    }
    cout << ans << "\n";
    return 0;
}
