#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int head[N], nxt[N << 1], to[N << 1], wt[N << 1], ec;
int f[N][N], sz[N], n, Q, i, a, b, c, j, k;
void add(int u, int v, int w) {
    ec++;
    to[ec] = v, wt[ec] = w, nxt[ec] = head[u], head[u] = ec;
}
void dfs(int u, int fa) {
    int e, v, i, j;
    sz[u] = 1, f[u][0] = 0;
    for (e = head[u]; e; e = nxt[e]) {
        v = to[e];
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
        for (i = sz[u]; i >= 1; i--) {
            for (j = 0; j < i && j <= sz[v]; j++) {
                if (f[u][i - j - 1] >= 0 && f[v][j] >= 0) {
                    int val = f[u][i - j - 1] + f[v][j] + wt[e];
                    if (val > f[u][i]) {
                        f[u][i] = val;
                    }
                }
            }
        }
    }
}
signed main() {
    cin >> n >> Q;
    for (i = 1; i < n; i++) {
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= Q; j++) {
            f[i][j] = -1;
        }
    }
    dfs(1, 0);
    cout << f[1][Q] << "\n";
    return 0;
}
