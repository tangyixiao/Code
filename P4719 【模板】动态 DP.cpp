#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int inf = 1e9 + 10;
struct mt {
    int n, m;
    int s[2][2];
};
mt operator*(const mt& a, const mt& b) {
    int n = a.n;
    int m = a.m;
    int k = b.m;
    mt res = mt();
    res.n = n;
    res.m = k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                res.s[i][j] = max(res.s[i][j], a.s[i][l] + b.s[l][j]);
            }
        }
    }
    return res;
}
struct sgt {
#define ls (u << 1)
#define rs ((u << 1) | 1)
#define mid ((le + ri) >> 1)
#define lp ls, le, mid
#define rp rs, mid + 1, ri
    mt s[N << 2];
    void push_up(int u) {
        s[u] = s[ls] * s[rs];
    }
    void upd(int u, int le, int ri, int x, mt a) {
        if (le == ri) {
            s[u] = a;
            return;
        }
        if (x <= mid)
            upd(lp, x, a);
        else
            upd(rp, x, a);
        push_up(u);
    }
    mt que(int u, int le, int ri, int x, int y) {
        if (x <= le && ri <= y) {
            return s[u];
        }
        if (y <= mid)
            return que(lp, x, y);
        if (x > mid)
            return que(rp, x, y);
        return que(lp, x, y) * que(rp, x, y);
    }
} t;
int n, a[N], q;
vector<int> e[N];
int fr[N], dep[N], sz[N], hs[N];
int dfn[N], cnt, top[N], ed[N];
int f[N][2], g[N][2];
mt h[N];
void dfs0(int u, int fa) {
    dep[u] = dep[fa] + 1;
    fr[u] = fa;
    sz[u] = 1;
    f[u][1] = a[u];
    for (int v : e[u]) {
        if (v == fa)
            continue;
        dfs0(v, u);
        sz[u] += sz[v];
        if (sz[hs[u]] < sz[v])
            hs[u] = v;
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][0], f[v][1]);
    }
}
void dfs1(int u, int t) {
    dfn[u] = ++cnt;
    top[u] = t;
    ed[t] = cnt;
    g[u][1] = a[u];
    if (!hs[u])
        return;
    dfs1(hs[u], t);
    for (int v : e[u]) {
        if (v == fr[u] || v == hs[u])
            continue;
        dfs1(v, v);
        g[u][0] += max(f[v][0], f[v][1]);
        g[u][1] += f[v][0];
    }
}
void rep(int i) {
    h[i] = {2, 2, {
                      {g[i][0], g[i][0]},
                      {g[i][1], -inf},
                  }};
}
void upd(int x, int val) {
    g[x][1] += val - a[x];
    a[x] = val;
    rep(x);
    while (x) {
        mt lst = t.que(1, 1, n, dfn[top[x]], ed[top[x]]);
        t.upd(1, 1, n, dfn[x], h[x]);
        mt now = t.que(1, 1, n, dfn[top[x]], ed[top[x]]);
        x = fr[top[x]];
        g[x][0] += max(now.s[0][0], now.s[1][0]) - max(lst.s[0][0], lst.s[1][0]);
        g[x][1] += now.s[0][0] - lst.s[0][0];
        rep(x);
    }
}
int que() {
    mt res = t.que(1, 1, n, 1, ed[1]);
    return max(res.s[0][0], res.s[1][0]);
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs0(1, 0);
    dfs1(1, 1);
    for (int i = 1; i <= n; i++) {
        rep(i);
    }
    for (int i = 1; i <= n; i++) {
        t.upd(1, 1, n, dfn[i], h[i]);
    }
    while (q--) {
        int x, val;
        cin >> x >> val;
        upd(x, val);
        cout << que() << "\n";
    }
}
