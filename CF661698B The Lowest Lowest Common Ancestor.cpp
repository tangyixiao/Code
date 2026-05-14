#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, LOG = 20;
int n, q, dep[N], fa[N], st[LOG][N], seg[N << 1];
vector<int> g[N];
inline int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int now = dep[u] - dep[v];
    for (int k = 0; k < LOG; ++k) {
        if (now & (1 << k)) {
            u = st[k][u];
        }
    }
    if (u == v) {
        return u;
    }
    for (int k = LOG - 1; k >= 0; --k) {
        if (st[k][u] != st[k][v]) {
            u = st[k][u];
            v = st[k][v];
        }
    }
    return st[0][u];
}
inline int ralca(int l, int r) {
    int res = -1;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            if (res == -1) {
                res = seg[l];
            } else {
                res = lca(res, seg[l]);
            }
            ++l;
        }
        if (r & 1) {
            --r;
            if (res == -1) {
                res = seg[r];
            } else {
                res = lca(res, seg[r]);
            }
        }
    }
    return res;
}
inline void bfs() {
    queue<int> qu;
    qu.push(1);
    fa[1] = 1;
    dep[1] = 1;
    for (; !qu.empty();) {
        int u = qu.front();
        qu.pop();
        for (int v : g[u]) {
            if (v != fa[u]) {
                fa[v] = u;
                dep[v] = dep[u] + 1;
                qu.push(v);
            }
        }
    }
    return;
}
inline void solve() {
    cin >> n >> q;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    for (int i = 1; i <= n; ++i) {
        st[0][i] = fa[i];
    }
    for (int k = 1; k < LOG; ++k) {
        for (int i = 1; i <= n; ++i) {
            st[k][i] = st[k - 1][st[k - 1][i]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        seg[n + i - 1] = i;
    }
    for (int i = n - 1; i > 0; --i) {
        seg[i] = lca(seg[i << 1], seg[i << 1 | 1]);
    }
    for (int l1, r1, l2, r2; q--;) {
        cin >> l1 >> r1 >> l2 >> r2;
        cout << dep[lca(ralca(l1 - 1, r1 - 1), ralca(l2 - 1, r2 - 1))] << '\n';
    }
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t--;) {
        solve();
    }
    return 0;
}