#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const long long INF = 1e18;
long long d[N][N];

signed main() {
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], (long long)w);
        d[v][u] = min(d[v][u], (long long)w);
    }
    cin >> a >> b >> c;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    long long ans = INF;
    for (int v = 1; v <= n; v++) {
        ans = min(ans, d[a][v] + d[b][v] + d[c][v]);
    }
    cout << ans << "\n";
    return 0;
}
