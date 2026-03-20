#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e5 + 5;
const int LOG = 18;
const ll INF = 1e18;

struct Edge {
    int u, v, w, id;
};

int n, m;
vector<Edge> edges;
vector<pair<int, int>> g[MAXN];
bool inMST[MAXN];
ll total = 0;

int f[MAXN], depth[MAXN], edge_id[MAXN];
int up[MAXN][LOG];

int dsu[MAXN];

ll ans_tree[MAXN];

inline int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

inline int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i)
        if (diff >> i & 1)
            u = up[u][i];
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i)
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    return up[u][0];
}

inline void jump(int x, int t, int w) {
    x = find(x);
    while (depth[x] > depth[t]) {
        int eid = edge_id[x];

        if (ans_tree[eid] == INF)
            ans_tree[eid] = w;

        dsu[x] = find(f[x]);
        x = find(x);
    }
    return;
}

inline void dfs(int u, int p) {
    f[u] = p;
    depth[u] = depth[p] + 1;
    for (auto [v, id] : g[u]) {
        if (v == p)
            continue;
        edge_id[v] = id;
        dfs(v, u);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    edges.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }

    vector<Edge> sorted = edges;
    sort(sorted.begin() + 1, sorted.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    vector<int> kuf(n + 1);
    for (int i = 1; i <= n; ++i)
        kuf[i] = i;
    function<int(int)> kfind = [&](int x) { return kuf[x] == x ? x : kuf[x] = kfind(kuf[x]); };

    for (int i = 1; i <= m; ++i) {
        Edge &e = sorted[i];
        if (e.u == e.v)
            continue;
        int fu = kfind(e.u), fv = kfind(e.v);
        if (fu != fv) {
            kuf[fu] = fv;
            inMST[e.id] = true;
            total += e.w;
            g[e.u].emplace_back(e.v, e.id);
            g[e.v].emplace_back(e.u, e.id);
        }
    }

    depth[1] = 0;
    dfs(1, 1);

    for (int i = 1; i <= n; ++i) {
        up[i][0] = f[i];
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    vector<Edge> nonTree;
    for (int i = 1; i <= m; ++i) {
        if (!inMST[i])
            nonTree.push_back(edges[i]);
    }
    sort(nonTree.begin(), nonTree.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    for (int i = 1; i <= n; ++i)
        dsu[i] = i;

    fill(ans_tree, ans_tree + m + 1, INF);

    for (auto &e : nonTree) {
        int u = e.u, v = e.v, w = e.w;
        if (u == v)
            continue;
        int l = lca(u, v);
        jump(u, l, w);
        jump(v, l, w);
    }

    vector<ll> ans(m + 1);
    for (int i = 1; i <= m; ++i) {
        if (inMST[i]) {
            if (ans_tree[i] == INF)
                ans[i] = -1;
            else
                ans[i] = total - edges[i].w + ans_tree[i];
        } else {
            ans[i] = total;
        }
    }

    for (int i = 1; i <= m; ++i)
        cout << ans[i] << '\n';

    return 0;
}