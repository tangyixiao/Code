#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, head[N], nxt[N], to[N], ec;
int dfn[N], low[N], clk, bridge;

void add(int u, int v) {
    ec++;
    to[ec] = v;
    nxt[ec] = head[u];
    head[u] = ec;
}

void tj(int u, int fe) {
    dfn[u] = low[u] = ++clk;
    for (int e = head[u]; e; e = nxt[e]) {
        if ((e ^ 1) == fe) {
            continue;
        }
        int v = to[e];
        if (!dfn[v]) {
            tj(v, e);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                bridge++;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ec = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tj(i, 0);
        }
    }
    cout << bridge << "\n";
    return 0;
}
