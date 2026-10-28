#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5, LOG = 18;
const ll INF = 1e18;

int n, m, f[N], dep[N], fe[N], up[N][LOG], dsu[N];
bool inT[N];
ll sum = 0, ans[N], mn[N];
vector<pair<int, int>> g[N];

struct E {
    int u, v, w, id;
} e[N], es[N];

int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int d = dep[u] - dep[v];
    for (int i = 0; i < LOG; i++) {
        if (d >> i & 1) {
            u = up[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i], v = up[v][i];
        }
    }
    return up[u][0];
}

void jump(int x, int t, int w) {
    x = find(x);
    for (; dep[x] > dep[t];) {
        if (mn[fe[x]] == INF) {
            mn[fe[x]] = w;
        }
        dsu[x] = find(f[x]);
        x = find(x);
    }
    return;
}

void dfs(int u, int p) {
    f[u] = p, dep[u] = dep[p] + 1;
    for (pair<int, int> v : g[u]) {
        if (v.first != p) {
            fe[v.first] = v.second;
            dfs(v.first, u);
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        es[i] = e[i];
    }
    sort(es + 1, es + m + 1, [](const E &a, const E &b) {
        return a.w < b.w;
    });
    for (int i = 1; i <= m; i++) {
        if (es[i].u == es[i].v) {
            continue;
        }
        int fu = find(es[i].u), fv = find(es[i].v);
        if (fu != fv) {
            dsu[fu] = fv, inT[es[i].id] = true, sum += es[i].w;
            g[es[i].u].push_back({es[i].v, es[i].id});
            g[es[i].v].push_back({es[i].u, es[i].id});
        }
    }
    dep[1] = 0;
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        up[i][0] = f[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    vector<E> nt;
    for (int i = 1; i <= m; i++) {
        if (!inT[i]) {
            nt.push_back(e[i]);
        }
    }
    sort(nt.begin(), nt.end(), [](const E &a, const E &b) {
        return a.w < b.w;
    });
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
    }
    fill(mn + 1, mn + m + 1, INF);
    for (E &ed : nt) {
        if (ed.u == ed.v) {
            continue;
        }
        int l = lca(ed.u, ed.v);
        jump(ed.u, l, ed.w);
        jump(ed.v, l, ed.w);
    }
    for (int i = 1; i <= m; i++) {
        if (inT[i]) {
            ans[i] = mn[i] == INF ? -1 : sum - e[i].w + mn[i];
        } else {
            ans[i] = sum;
        }
        cout << ans[i] << "\n";
    }
    return 0;
}
