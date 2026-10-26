#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
using ll = long long;
const int N = 1e5 + 5, M = 1e2 + 5;
const ll INF = 4e18;
int n, q, fa[N], dep[N], sz[N], son[N], top[N], dfn[N], rev[N], hp[N], lp[N], pos[N], ord[N], st[N], cnt, h, c, k;
pair<int, int> seg[M];
vector<int> e[N];
struct node {
    ll mn, se, sum, add;
    int cnt;
} tr[N * 4];

void build(int o, int l, int r) {
    tr[o].se = INF, tr[o].cnt = r - l + 1;
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    build(o << 1, l, m), build(o << 1 | 1, m + 1, r);
}

void add(int o, ll v, int len) {
    tr[o].mn += v, tr[o].sum += v * len, tr[o].add += v;
    if (tr[o].se != INF) {
        tr[o].se += v;
    }
}

void raise(int o, ll v) {
    if (v > tr[o].mn) {
        tr[o].sum += (v - tr[o].mn) * tr[o].cnt, tr[o].mn = v;
    }
}

void push(int o, int l, int r) {
    int m = (l + r) >> 1;
    if (tr[o].add) {
        add(o << 1, tr[o].add, m - l + 1), add(o << 1 | 1, tr[o].add, r - m), tr[o].add = 0;
    }
    raise(o << 1, tr[o].mn), raise(o << 1 | 1, tr[o].mn);
}

void pull(int o) {
    node &a = tr[o << 1], &b = tr[o << 1 | 1];
    tr[o].sum = a.sum + b.sum, tr[o].mn = min(a.mn, b.mn), tr[o].cnt = 0;
    if (a.mn == tr[o].mn) {
        tr[o].cnt += a.cnt;
    }
    if (b.mn == tr[o].mn) {
        tr[o].cnt += b.cnt;
    }
    tr[o].se = min(a.mn == tr[o].mn ? a.se : a.mn, b.mn == tr[o].mn ? b.se : b.mn);
}

void change(int o, int l, int r, ll v, int t) {
    for (; k <= c && seg[k].second < l; k++) {
    }
    if (k > c || seg[k].first > r) {
        return;
    }
    if (t == 2 && tr[o].mn >= v) {
        return;
    }
    if (seg[k].first <= l && r <= seg[k].second) {
        if (t == 1) {
            add(o, v, r - l + 1);
            return;
        }
        if (v < tr[o].se) {
            raise(o, v);
            return;
        }
    }
    int m = (l + r) >> 1;
    push(o, l, r);
    change(o << 1, l, m, v, t), change(o << 1 | 1, m + 1, r, v, t);
    pull(o);
}

ll query(int o, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return tr[o].sum;
    }
    int m = (l + r) >> 1;
    ll ans = 0;
    push(o, l, r);
    if (x <= m) {
        ans += query(o << 1, l, m, x, y);
    }
    if (y > m) {
        ans += query(o << 1 | 1, m + 1, r, x, y);
    }
    return ans;
}

void modify(int l, int r) {
    if (hp[l - 1] < hp[r]) {
        seg[++c] = {hp[l - 1] + 1, hp[r]};
    }
    if (lp[l - 1] < lp[r]) {
        seg[++c] = {h + lp[l - 1] + 1, h + lp[r]};
    }
}

inline void solve() {
    cin >> n >> q;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
    }
    ord[1] = 1, dep[1] = 1;
    for (int i = 1, j = 1; i <= n; i++) {
        for (int v : e[ord[i]]) {
            if (v != fa[ord[i]]) {
                fa[v] = ord[i], dep[v] = dep[ord[i]] + 1, ord[++j] = v;
            }
        }
    }
    for (int i = n; i; i--) {
        sz[ord[i]]++;
        if (fa[ord[i]]) {
            sz[fa[ord[i]]] += sz[ord[i]];
            if (sz[ord[i]] > sz[son[fa[ord[i]]]]) {
                son[fa[ord[i]]] = ord[i];
            }
        }
    }
    st[++cnt] = 1;
    for (; cnt;) {
        int u = st[cnt--];
        for (int v = u; v; v = son[v]) {
            top[v] = u, dfn[v] = ++h, rev[h] = v;
            for (int w : e[v]) {
                if (w != fa[v] && w != son[v]) {
                    st[++cnt] = w;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        hp[i] = hp[i - 1] + (son[rev[i]] != 0), lp[i] = lp[i - 1];
        for (int v : e[rev[i]]) {
            if (v != fa[rev[i]] && v != son[rev[i]]) {
                lp[i]++;
            }
        }
    }
    h = hp[n], pos[1] = n;
    for (int i = 1; i <= n; i++) {
        if (son[rev[i]]) {
            pos[son[rev[i]]] = hp[i];
        }
        int j = h + lp[i - 1];
        for (int v : e[rev[i]]) {
            if (v != fa[rev[i]] && v != son[rev[i]]) {
                pos[v] = ++j;
            }
        }
    }
    build(1, 1, n);
    for (int i = 1, t, u, v; i <= q; i++) {
        ll w;
        cin >> t >> u;
        if (t == 3) {
            int l = dfn[u], r = l + sz[u] - 1;
            ll ans = query(1, 1, n, pos[u], pos[u]);
            if (hp[l - 1] < hp[r]) {
                ans += query(1, 1, n, hp[l - 1] + 1, hp[r]);
            }
            if (lp[l - 1] < lp[r]) {
                ans += query(1, 1, n, h + lp[l - 1] + 1, h + lp[r]);
            }
            cout << ans << "\n";
        } else {
            cin >> v >> w, c = 0;
            for (; top[u] != top[v];) {
                if (dep[top[u]] < dep[top[v]]) {
                    swap(u, v);
                }
                modify(dfn[top[u]], dfn[u]), u = fa[top[u]];
            }
            if (dep[u] > dep[v]) {
                swap(u, v);
            }
            modify(dfn[u], dfn[v]), seg[++c] = {pos[u], pos[u]};
            if (fa[u]) {
                seg[++c] = {pos[fa[u]], pos[fa[u]]};
            }
            sort(seg + 1, seg + c + 1), k = 0;
            for (int j = 1; j <= c; j++) {
                if (k && seg[j].first <= seg[k].second + 1) {
                    seg[k].second = max(seg[k].second, seg[j].second);
                } else {
                    seg[++k] = seg[j];
                }
            }
            c = k, k = 1, change(1, 1, n, w, t);
        }
    }
}
} // namespace TANGYIXIAO

signed main() {
    freopen("trim.in", "r", stdin), freopen("trim.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    TANGYIXIAO::solve();
    return 0;
}
