#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, q, mod, a[N];

namespace seg {
    struct node {
        int l, r, sum, add, mu;
    } tr[N * 4];

    inline void psu(int u) {
        tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
        return;
    }

    inline void recall(node& t, int add, int mu) { // rerererererecall bitset
        t.sum = (t.sum * mu + (t.r - t.l + 1) * add) % mod;
        t.mu = (t.mu * mu) % mod;
        t.add = (t.add * mu + add) % mod;
        return;
    }

    inline void psd(int u) {
        recall(tr[u << 1], tr[u].add, tr[u].mu);
        recall(tr[u << 1 | 1], tr[u].add, tr[u].mu);
        tr[u].add = 0;
        tr[u].mu = 1;
        return;
    }

    inline void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 0, 1};
        if (l == r) {
            tr[u].sum = a[l] % mod;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        psu(u);
        return;
    }

    inline void modmu(int u, int l, int r, int k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            recall(tr[u], 0, k);
            return;
        }
        psd(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) {
            modmu(u << 1, l, r, k);
        }
        if (r > mid) {
            modmu(u << 1 | 1, l, r, k);
        }
        psu(u);
        return;
    }

    inline void modadd(int u, int l, int r, int k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            recall(tr[u], k, 1);
            return;
        }
        psd(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) {
            modadd(u << 1, l, r, k);
        }
        if (r > mid) {
            modadd(u << 1 | 1, l, r, k);
        }
        psu(u);
        return;
    }
    inline int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].sum;
        }
        psd(u);
        int mid = (tr[u].l + tr[u].r) >> 1, sum = 0;
        if (l <= mid) {
            sum = (sum + query(u << 1, l, r)) % mod;
        }
        if (r > mid) {
            sum = (sum + query(u << 1 | 1, l, r)) % mod;
        }
        return sum % mod;
    }
} // namespace seg
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("seg.in", "r", stdin);
    freopen("seg.out", "w", stdout);
    cin >> n >> q >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    seg::build(1, 1, n);
    for (int op, x, y, k; q--;) {
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> k;
            seg::modmu(1, x, y, k % mod);
        } else if (op == 2) {
            cin >> k;
            seg::modadd(1, x, y, k % mod);
        } else {
            cout << seg::query(1, x, y) << "\n";
        }
    }
    return 0;
}