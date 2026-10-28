#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, LOG = 18, INF = 1e9;

int n, k, q, fa[N][LOG], dep[N], pd[N];
vector<int> g[N];

void dfs(int u, int p) {
    fa[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
        if (v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
    return;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int d = dep[u] - dep[v];
    for (int i = 0; i < LOG; i++) {
        if (d >> i & 1) {
            u = fa[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}

int dist(int u, int v) {
    int w = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[w];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> q;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    dep[1] = 0;
    dfs(1, 1);
    if (k > 0) {
        queue<int> qu;
        fill(pd + 1, pd + n + 1, -1);
        for (int i = 1, p; i <= k; i++) {
            cin >> p;
            pd[p] = 0;
            qu.push(p);
        }
        for (; !qu.empty();) {
            int u = qu.front();
            qu.pop();
            for (int v : g[u]) {
                if (pd[v] == -1) {
                    pd[v] = pd[u] + 1;
                    qu.push(v);
                }
            }
        }
    } else {
        fill(pd + 1, pd + n + 1, INF);
    }
    for (; q--;) {
        int u, v;
        cin >> u >> v;
        int ans = dist(u, v);
        if (k > 0) {
            ans = min(ans, pd[u] + pd[v]);
        }
        cout << ans << "\n";
    }
    return 0;
}
