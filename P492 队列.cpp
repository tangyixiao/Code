#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int M = 1e5 + 5;

int ch[N][2], fa[N], pr[N], nd[M], sp[M], m, n, q, ct, root;
long long w[N], sz[N], lo[N], lim;
int oa[M], ob[M], qx[M];
char qc[M];

inline void init(int x, long long v, long long b) {
    ch[x][0] = ch[x][1] = fa[x] = 0;
    w[x] = sz[x] = v, lo[x] = b;
    unsigned t = 19260817u + x * 2654435761u;
    t ^= t << 13, t ^= t >> 17, t ^= t << 5;
    pr[x] = t & 0x7fffffff;
}

inline void pushup(int x) {
    sz[x] = sz[ch[x][0]] + w[x] + sz[ch[x][1]];
}

inline void split(int x, long long k, int &a, int &b) {
    if (!x) {
        a = b = 0;
        return;
    }
    if (sz[ch[x][0]] >= k) {
        b = x;
        split(ch[x][0], k, a, ch[b][0]), fa[ch[b][0]] = b, pushup(b), fa[b] = 0;
    } else {
        a = x;
        split(ch[x][1], k - sz[ch[x][0]] - w[x], ch[a][1], b), fa[ch[a][1]] = a, pushup(a), fa[a] = 0;
    }
}

inline int merge(int a, int b) {
    if (!a || !b) {
        int r = a | b;
        fa[r] = 0;
        return r;
    }
    if (pr[a] < pr[b]) {
        ch[a][1] = merge(ch[a][1], b), fa[ch[a][1]] = a, pushup(a), fa[a] = 0;
        return a;
    }
    ch[b][0] = merge(a, ch[b][0]), fa[ch[b][0]] = b, pushup(b), fa[b] = 0;
    return b;
}

inline long long rk(int x) {
    long long r = sz[ch[x][0]] + w[x];
    while (fa[x]) {
        int f = fa[x];
        if (ch[f][1] == x) {
            r += sz[ch[f][0]] + w[f];
        }
        x = f;
    }
    return r;
}

inline int add(int v, long long b) {
    init(++ct, v, b), root = merge(root, ct);
    return ct;
}

inline int idx(int v) {
    return lower_bound(sp + 1, sp + m + 1, v) - sp;
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> oa[i] >> ob[i], sp[++m] = oa[i], sp[++m] = ob[i];
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> qc[i] >> qx[i];
        if (qc[i] == 'P') {
            sp[++m] = qx[i];
        } else {
            lim = max(lim, (long long)qx[i]);
        }
    }
    sort(sp + 1, sp + m + 1);
    m = unique(sp + 1, sp + m + 1) - sp - 1;
    lim = max(lim, (long long)sp[m]);
}

inline void solve() {
    for (int j = 1; j <= m; ++j) {
        long long l = j > 1 ? sp[j - 1] + 1 : 1, r = sp[j] - 1;
        if (l <= r) {
            add(r - l + 1, l);
        }
        nd[j] = add(1, sp[j]);
    }
    if (sp[m] + 1 <= lim) {
        add(lim - sp[m], sp[m] + 1);
    }
    for (int i = 1; i <= n; ++i) {
        int a = nd[idx(oa[i])], b = nd[idx(ob[i])], x, y, z, t;
        split(root, rk(a) - 1, x, y), split(y, w[a], y, z), root = merge(x, z);
        split(root, rk(b) - 1, x, t), root = merge(merge(x, y), t);
    }
    for (int i = 1; i <= q; ++i) {
        if (qc[i] == 'P') {
            cout << rk(nd[idx(qx[i])]) << "\n";
        } else {
            long long k = qx[i];
            int x = root;
            while (x) {
                if (k <= sz[ch[x][0]]) {
                    x = ch[x][0];
                } else if (k <= sz[ch[x][0]] + w[x]) {
                    cout << lo[x] + k - sz[ch[x][0]] - 1 << "\n";
                    break;
                } else {
                    k -= sz[ch[x][0]] + w[x], x = ch[x][1];
                }
            }
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}