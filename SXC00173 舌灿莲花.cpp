#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 1e3 + 5;
int n, m;
int ec, head[N], nxt[2 * M], to[2 * M], lab[2 * M];
int dis[N][N], qa[N * N], qb[N * N], ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        nxt[++ec] = head[u], to[ec] = v, lab[ec] = c, head[u] = ec;
        nxt[++ec] = head[v], to[ec] = u, lab[ec] = c, head[v] = ec;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = -1;
        }
    }
    int h = 0, tl = 0;
    dis[1][n] = 0, qa[0] = 1, qb[0] = n, tl = 1;
    ans = -1;
    for (; h < tl;) {
        int u = qa[h], v = qb[h], d = dis[u][v];
        h++;
        if (u == v && (ans == -1 || d * 2 < ans)) {
            ans = d * 2;
        }
        for (int e = head[u]; e; e = nxt[e]) {
            if (to[e] == v && (ans == -1 || d * 2 + 1 < ans)) {
                ans = d * 2 + 1;
            }
            for (int g = head[v]; g; g = nxt[g]) {
                if (lab[e] != lab[g]) {
                    continue;
                }
                int nu = to[e], nv = to[g];
                if (dis[nu][nv] != -1) {
                    continue;
                }
                dis[nu][nv] = d + 1;
                qa[tl] = nu, qb[tl] = nv, tl++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
