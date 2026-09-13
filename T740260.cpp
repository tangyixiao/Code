#include <bits/stdc++.h>
using namespace std;

const int N = 100005, Q = 100005, V = N + Q, L = 22;

struct Query {
    int op, y;
    long long x;
} p[Q];

int n, q, m, h, tim;
int a[N], lg[N], d[N], nxt[Q], hd[L], need[L];
int v[2][N], r[2][N], sz[2];
int cnt[V], vis[V];
long long raw[N], w[V], ans[Q];

void add(int o, int x, int len) {
    if (!len) return;
    int t = r[o][sz[o]] + len;
    if (sz[o] && v[o][sz[o]] == x) {
        r[o][sz[o]] = t;
    } else {
        ++sz[o];
        v[o][sz[o]] = x;
        r[o][sz[o]] = t;
    }
}

void solve() {
    if (!h) return;

    int mx = 0, at = 0, b = 0;
    for (int k = 2; k <= h; ++k)
        mx = max(mx, need[k]);
    ++tim;
    for (int i = 1; i <= mx; ++i) {
        int x = a[i];
        if (vis[x] != tim) {
            vis[x] = tim;
            cnt[x] = 0;
        }
        ++cnt[x];
        if (!b || cnt[x] > cnt[b] || (cnt[x] == cnt[b] && x < b))
            b = x;
        if (b != x) {
            at = i;
            break;
        }
    }

    int nh = 0;
    for (int k = 2; k <= h; ++k) {
        int t = hd[k];
        hd[k] = need[k] = 0;
        while (t) {
            int j = nxt[t], y = p[t].y;
            if (!at || y < at) {
                ans[t] = w[a[y]];
            } else if (p[t].x >= lg[y - at + 1] + 2) {
                ans[t] = w[b];
            } else {
                nxt[t] = hd[k];
                hd[k] = t;
                need[k] = max(need[k], y);
                nh = max(nh, k);
            }
            t = j;
        }
    }
    h = nh;
    if (!h) return;

    for (int i = h - 1; i >= 2; --i)
        need[i] = max(need[i], need[i + 1]);

    sz[0] = 0;
    for (int i = 1; i <= need[2]; ++i)
        add(0, a[i], 1);

    int u = 0;
    for (int k = 2; k <= h; ++k) {
        int o = u ^ 1, s = 0, best = 0;
        sz[o] = 0;
        ++tim;
        for (int i = 1; i <= sz[u] && s < need[k]; ++i) {
            int x = v[u][i], len = min(r[u][i], need[k]) - s;
            if (vis[x] != tim) {
                vis[x] = tim;
                cnt[x] = 0;
            }
            if (!best) best = x;
            if (best == x) {
                add(o, x, len);
            } else {
                int t = cnt[best] - cnt[x] - (x < best);
                t = min(len, t);
                add(o, best, t);
                add(o, x, len - t);
                if (t < len) best = x;
            }
            cnt[x] += len;
            s += len;
        }
        bool same = sz[o] <= sz[u];
        for (int j = 1; same && j <= sz[o]; ++j)
            if (v[o][j] != v[u][j] ||
                r[o][j] != min(r[u][j], need[k]))
                same = false;
        u = o;

        if (sz[u] == 1) {
            for (int j = k; j <= h; ++j)
                for (int i = hd[j]; i; i = nxt[i])
                    ans[i] = w[v[u][1]];
            break;
        }

        if (hd[k] || same) {
            int l = 1;
            for (int j = 1; j <= sz[u]; ++j) {
                fill(d + l, d + r[u][j] + 1, v[u][j]);
                l = r[u][j] + 1;
            }
            for (int i = hd[k]; i; i = nxt[i])
                ans[i] = w[d[p[i].y]];
        }
        if (same) {
            for (int j = k + 1; j <= h; ++j)
                for (int i = hd[j]; i; i = nxt[i])
                    ans[i] = w[d[p[i].y]];
            break;
        }
    }

    for (int i = 2; i <= h; ++i)
        hd[i] = need[i] = 0;
    h = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> raw[i];
        w[++m] = raw[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> p[i].op >> p[i].x >> p[i].y;
        if (p[i].op == 2) w[++m] = p[i].x;
    }

    sort(w + 1, w + m + 1);
    m = int(unique(w + 1, w + m + 1) - w - 1);
    for (int i = 1; i <= n; ++i)
        a[i] = int(lower_bound(w + 1, w + m + 1, raw[i]) - w);
    for (int i = 1; i <= q; ++i)
        if (p[i].op == 2)
            p[i].x = lower_bound(w + 1, w + m + 1, p[i].x) - w;
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[(i + 1) / 2] + 1;

    for (int i = 1; i <= q; ++i) {
        int x = int(p[i].x), y = p[i].y;
        if (p[i].op == 2) {
            if (a[y] != x) {
                solve();
                a[y] = x;
            }
        } else if (x == 1) {
            ans[i] = w[a[y]];
        } else if (y == 1) {
            ans[i] = w[a[1]];
        } else {
            x = min(x, lg[y - 1] + 2);
            nxt[i] = hd[x];
            hd[x] = i;
            need[x] = max(need[x], y);
            h = max(h, x);
        }
    }
    solve();

    for (int i = 1; i <= q; ++i)
        if (p[i].op == 1)
            cout << ans[i] << '\n';
    return 0;
}
