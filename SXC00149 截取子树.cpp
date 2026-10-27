#include <bits/stdc++.h>
using namespace std;
const int N = 155;
const int INF = 1e9;
int n, p, i, fa, x, ans, ec;
int head[N], nxt[N], to[N], sz[N], f[N][N], g[N];
void dfs(int u) {
    sz[u] = 1;
    f[u][1] = 0;
    for (int e = head[u]; e != -1; e = nxt[e]) {
        int c = to[e];
        dfs(c);
        for (i = 1; i <= sz[u] + sz[c]; i++) {
            g[i] = INF;
        }
        for (i = 1; i <= sz[u]; i++) {
            for (int j = 0; j <= sz[c]; j++) {
                int w = f[u][i] + (j == 0 ? 1 : f[c][j]);
                if (w < g[i + j]) {
                    g[i + j] = w;
                }
            }
        }
        sz[u] += sz[c];
        for (i = 1; i <= sz[u]; i++) {
            f[u][i] = g[i];
        }
    }
}
signed main() {
    scanf("%d%d", &n, &p);
    for (i = 1; i <= n; i++) {
        head[i] = -1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = INF;
        }
    }
    for (i = 1; i < n; i++) {
        scanf("%d%d", &fa, &x);
        to[i] = x, nxt[i] = head[fa], head[fa] = i;
    }
    dfs(1);
    ans = INF;
    for (i = 1; i <= n; i++) {
        int w = f[i][p] + (i == 1 ? 0 : 1);
        if (w < ans) {
            ans = w;
        }
    }
    printf("%d\n", ans);
    return 0;
}
