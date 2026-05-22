#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
typedef long long ll;
const int N = 100005;

ll sum[N << 2], lz[N << 2];
int n, m, a[N], sz[N], dep[N], fa[N], son[N], top[N], dfn[N], id[N], tim;
vector<int> G[N];
inline void dfs1(int u, int f) {
    sz[u] = 1;
    dep[u] = dep[f] + 1;
    fa[u] = f;
    for (int v : G[u]) {
        if (v != f) {
            dfs1(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[son[u]]) {
                son[u] = v;
            }
        }
    }
    return;
}

inline void dfs2(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++tim;
    id[tim] = u;
    if (son[u]) {
        dfs2(son[u], tp);
    }
    for (int v : G[u]) {
        if (v != fa[u] && v != son[u]) {
            dfs2(v, v);
        }
    }
    return;
}

inline void build(int o, int l, int r) {
    if (l == r) {
        sum[o] = a[id[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
    return;
}

inline void apply(int o, int l, int r, ll v) {
    sum[o] += (r - l + 1) * v;
    lz[o] += v;
    return;
}

inline void pushdown(int o, int l, int r) {
    if (lz[o]) {
        int mid = (l + r) >> 1;
        apply(o << 1, l, mid, lz[o]);
        apply(o << 1 | 1, mid + 1, r, lz[o]);
        lz[o] = 0;
    }
    return;
}

inline void add(int o, int l, int r, int ql, int qr, ll v) {
    if (ql <= l && r <= qr) {
        apply(o, l, r, v);
        return;
    }
    pushdown(o, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) {
        add(o << 1, l, mid, ql, qr, v);
    }
    if (qr > mid) {
        add(o << 1 | 1, mid + 1, r, ql, qr, v);
    }
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
    return;
}

inline ll query(int o, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return sum[o];
    }
    pushdown(o, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (ql <= mid) {
        res += query(o << 1, l, mid, ql, qr);
    }
    if (qr > mid) {
        res += query(o << 1 | 1, mid + 1, r, ql, qr);
    }
    return res;
}

inline void updp(int x, ll v) {
    add(1, 1, n, dfn[x], dfn[x], v);
    return;
}

inline void upds(int x, ll v) {
    add(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, v);
    return;
}

inline ll queryp(int x) {
    ll ans = 0;
    while (top[x] != 1) {
        ans += query(1, 1, n, dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    ans += query(1, 1, n, dfn[1], dfn[x]);
    return ans;
}

inline void solve(int Task_Id) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    for (int op, x; m--;) {
        ll v;
        cin >> op >> x;
        if (op == 1) {
            cin >> v;
            updp(x, v);
        } else if (op == 2) {
            cin >> v;
            upds(x, v);
        } else {
            cout << queryp(x) << "\n";
        }
    }

    return;
}
} // namespace TANGYIXIAO

signed main() {
    TANGYIXIAO::solve(1);
    return 0;
}