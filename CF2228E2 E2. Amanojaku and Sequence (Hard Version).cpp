#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, F = 2000005, N = 300005;

long long fact[F], invfact[F];
int a[N];

struct Node {
    int len;
    long long sx;
    int sy, sp, sq, sp2, sq2, spq;
} tree[4 * N];

inline long long modpow(long long x, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1)
            r = r * x % mod;
        x = x * x % mod;
        e >>= 1;
    }
    return r;
}
inline int C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

inline void pull(int idx) {
    int lc = (idx << 1), rc = (idx << 1) + 1;
    Node &L = tree[lc], &R = tree[rc];
    Node &P = tree[idx];
    P.len = L.len + R.len;
    P.sx = L.sx + R.sx;
    P.sy = L.sy + R.sy;
    int LX = L.sx % mod;
    int LY = L.sy % mod;
    P.sp = (L.sp + (1LL * R.len * LX + R.sp) % mod) % mod;
    P.sq = (L.sq + (1LL * R.len * LY + R.sq) % mod) % mod;
    P.sp2 = (L.sp2 + (1LL * R.len * LX % mod * LX % mod + 2LL * LX % mod * R.sp % mod + R.sp2) % mod) % mod;
    P.sq2 = (L.sq2 + (1LL * R.len * LY % mod * LY % mod + 2LL * LY % mod * R.sq % mod + R.sq2) % mod) % mod;
    P.spq = (L.spq + (1LL * R.len * LX % mod * LY % mod + 1LL * LX * R.sq % mod + 1LL * LY * R.sp % mod + R.spq) % mod) % mod;

    return;
}

inline void build(int idx, int l, int r) {
    if (l == r) {
        int v = a[l];
        int x, y;
        if (v == -1) {
            x = 0;
            y = 1;
        } else {
            x = v;
            y = 0;
        }
        tree[idx].len = 1;
        tree[idx].sx = x;
        tree[idx].sy = y;
        tree[idx].sp = x % mod;
        tree[idx].sq = y % mod;
        tree[idx].sp2 = (1LL * x * x) % mod;
        tree[idx].sq2 = (1LL * y * y) % mod;
        tree[idx].spq = (1LL * x * y) % mod;
        return;
    }
    int mid = (l + r) >> 1;
    build((idx << 1), l, mid);
    build((idx << 1) + 1, mid + 1, r);
    pull(idx);
    return;
}

inline void update(int idx, int l, int r, int p, int v) {
    if (l == r) {
        int x, y;
        if (v == -1) {
            x = 0;
            y = 1;
        } else {
            x = v;
            y = 0;
        }
        tree[idx].sx = x;
        tree[idx].sy = y;
        tree[idx].sp = x % mod;
        tree[idx].sq = y % mod;
        tree[idx].sp2 = (1LL * x * x) % mod;
        tree[idx].sq2 = (1LL * y * y) % mod;
        tree[idx].spq = (1LL * x * y) % mod;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) {
        update((idx << 1), l, mid, p, v);
    } else {
        update((idx << 1) + 1, mid + 1, r, p, v);
    }
    pull(idx);
    return;
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query((idx << 1), l, mid, ql, qr);
    if (ql > mid)
        return query((idx << 1) + 1, mid + 1, r, ql, qr);
    Node L = query((idx << 1), l, mid, ql, qr);
    Node R = query((idx << 1) + 1, mid + 1, r, ql, qr);
    Node res;
    res.len = L.len + R.len;
    res.sx = L.sx + R.sx;
    res.sy = L.sy + R.sy;
    int LX = L.sx % mod;
    int LY = L.sy % mod;
    res.sp = (L.sp + (1LL * R.len * LX + R.sp) % mod) % mod;
    res.sq = (L.sq + (1LL * R.len * LY + R.sq) % mod) % mod;
    res.sp2 = (L.sp2 + (1LL * R.len * LX % mod * LX % mod + 2LL * LX % mod * R.sp % mod + R.sp2) % mod) % mod;
    res.sq2 = (L.sq2 + (1LL * R.len * LY % mod * LY % mod + 2LL * LY % mod * R.sq % mod + R.sq2) % mod) % mod;
    res.spq = (L.spq + (1LL * R.len * LX % mod * LY % mod + 1LL * LX * R.sq % mod + 1LL * LY * R.sp % mod + R.spq) % mod) % mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for (int i = 1; i < F; ++i)
        fact[i] = fact[i - 1] * i % mod;
    invfact[F - 1] = modpow(fact[F - 1], mod - 2);
    for (int i = F - 2; i >= 0; --i)
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        build(1, 1, n);
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int p, v;
                cin >> p >> v;
                update(1, 1, n, p, v);
                a[p] = v;
            } else {
                int l, r, m;
                cin >> l >> r >> m;
                Node cur = query(1, 1, n, l, r);
                long long S = cur.sx;
                int k = cur.sy;
                if (S > m) {
                    cout << "0\n";
                    continue;
                }
                int R = m - S;
                if (k == 0) {
                    cout << (R == 0 ? cur.sp2 : 0) << '\n';
                } else {
                    int tot = C(R + k - 1, k - 1);
                    int c1 = C(R + k - 1, k);
                    int c2 = C(R + k - 1, k + 1);
                    long long ans = (1LL * tot * cur.sp2) % mod;
                    ans = (ans + 2LL * c1 % mod * cur.spq) % mod;
                    ans = (ans + 1LL * (c1 + c2) % mod * cur.sq) % mod;
                    ans = (ans + 1LL * c2 * cur.sq2) % mod;
                    cout << ans << '\n';
                }
            }
        }
    }
    return 0;
}