#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m;
double x[N], y[N], g[N][N], d[N];
bool v[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = i == j ? 0 : 1e9;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        double w = hypot(x[u] - x[v], y[u] - y[v]);
        if (w < g[u][v]) {
            g[u][v] = g[v][u] = w;
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    int s, t;
    cin >> s >> t;
    for (int i = 0; i <= n; i++) {
        d[i] = 1e9, v[i] = false;
    }
    d[s] = 0;
    for (int k = 1; k <= n; k++) {
        int u = 0;
        for (int i = 1; i <= n; i++) {
            if (!v[i] && d[i] < d[u]) {
                u = i;
            }
        }
        if (d[u] >= 1e9) {
            break;
        }
        v[u] = true;
        for (int i = 1; i <= n; i++) {
            if (v[i]) {
                continue;
            }
            if (d[u] + g[u][i] < d[i]) {
                d[i] = d[u] + g[u][i];
            }
        }
    }
    printf("%.2f\n", d[t]);
    return 0;
}