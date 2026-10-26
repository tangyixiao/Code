#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
constexpr int N = 2e5 + 5, M = 2e6 + 5, P = 998244353, L = 18;
struct edge {
    int x, y, w;
} e[N];
int n, k, m, q, tot, num, c, x, y, s, w, last;
int f[N], rt[N], a[N], b[N], pw[N], up[N][L];
int ls[M], rs[M], cnt[M], sum[M];

inline int find(int x) {
    for (; f[x] != x;) { f[x] = f[f[x]], x = f[x]; }
    return x;
}

void ins(int &p, int l, int r, int x) {
    p = ++num, sum[p] = 1;
    if (l == r) {
        cnt[p] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        ins(ls[p], l, mid, x);
    } else {
        ins(rs[p], mid + 1, r, x);
    }
}

int merge(int u, int v, int l, int r) {
    if (!u || !v) { return u | v; }
    if (l == r) {
        cnt[u] += cnt[v], sum[u] = pw[cnt[u]] - 1;
        return u;
    }
    int mid = (l + r) >> 1;
    ls[u] = merge(ls[u], ls[v], l, mid), rs[u] = merge(rs[u], rs[v], mid + 1, r);
    sum[u] = (sum[ls[u]] + sum[rs[u]]) % P;
    return u;
}

inline void solve() {
    cin >> n >> k >> m >> q;
    tot = n, pw[0] = 1;
    for (int i = 1; i <= n; i++) { pw[i] = pw[i - 1] * 2 % P; }
    for (int i = 1; i <= n; i++) {
        cin >> c;
        f[i] = i, a[i] = k + 1, ins(rt[i], 1, k, c);
    }
    for (int i = 1; i <= m; i++) { cin >> e[i].x >> e[i].y >> e[i].w; }
    sort(e + 1, e + m + 1, [](const edge &x, const edge &y) { return x.w < y.w; });
    for (int i = 1; i <= m; i++) {
        x = find(e[i].x), y = find(e[i].y);
        if (x == y) { continue; }
        ++tot, f[tot] = tot, f[x] = f[y] = tot, up[x][0] = up[y][0] = tot, b[tot] = e[i].w;
        rt[tot] = merge(rt[x], rt[y], 1, k), a[tot] = (k + sum[rt[tot]]) % P;
    }
    for (int i = tot; i >= 1; i--) {
        for (int j = 1; j < L; j++) { up[i][j] = up[up[i][j - 1]][j - 1]; }
    }
    for (int i = 1; i <= q; i++) {
        cin >> s >> w;
        s ^= last, w ^= last;
        for (int j = L - 1; j >= 0; j--) {
            if (up[s][j] && b[up[s][j]] <= w) { s = up[s][j]; }
        }
        cout << (last = a[s]) << "\n";
    }
}
} // namespace TANGYIXIAO

signed main() {
    freopen("garden.in", "r", stdin);
    freopen("garden.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    TANGYIXIAO::solve();
    return 0;
}
