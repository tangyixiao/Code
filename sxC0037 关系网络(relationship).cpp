#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, x, y, i, j, h, t, u, v;
int g[N][N], d[N], q[N * N];
signed main() {
    cin >> n >> x >> y;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
        d[i] = -1;
    }
    h = 0;
    t = 0;
    q[t++] = x;
    d[x] = 0;
    while (h < t) {
        u = q[h++];
        for (v = 1; v <= n; v++) {
            if (g[u][v] == 1 && d[v] == -1) {
                d[v] = d[u] + 1;
                q[t++] = v;
            }
        }
    }
    cout << d[y] - 1 << "\n";
    return 0;
}
