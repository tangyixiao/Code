#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// 欧几里得算法，计算绝对值后的gcd
ll gcd(ll a, ll b) {
    a = llabs(a);
    b = llabs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 树状数组，用于维护差分数组的前缀和（即原数组a的值）
class BIT {
    vector<ll> tree;
    int n;

public:
    BIT(int n) : n(n), tree(n + 1, 0) {}

    void add(int idx, ll delta) {
        while (idx <= n) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    ll sum(int idx) {
        ll res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

// 线段树，维护差分数组绝对值的区间gcd
class SegTree {
    vector<ll> seg;
    int n;

    void build(int node, int l, int r, const vector<ll>& arr) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, arr);
        build(node * 2 + 1, mid + 1, r, arr);
        seg[node] = gcd(seg[node * 2], seg[node * 2 + 1]);
    }

public:
    SegTree(int n, const vector<ll>& arr) : n(n) {
        seg.resize(4 * n);
        build(1, 1, n, arr);
    }

    void update(int node, int l, int r, int idx, ll val) {
        if (l == r) {
            seg[node] = llabs(val);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);
        seg[node] = gcd(seg[node * 2], seg[node * 2 + 1]);
    }

    ll query(int node, int l, int r, int ql, int qr) {
        if (ql > qr)
            return 0; // 空区间gcd为0
        if (ql <= l && r <= qr)
            return seg[node];
        int mid = (l + r) / 2;
        ll res = 0;
        if (ql <= mid)
            res = gcd(res, query(node * 2, l, mid, ql, qr));
        if (qr > mid)
            res = gcd(res, query(node * 2 + 1, mid + 1, r, ql, qr));
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // 差分数组B
    vector<ll> B(n + 1);
    B[1] = a[1];
    for (int i = 2; i <= n; ++i)
        B[i] = a[i] - a[i - 1];

    // 树状数组初始化
    BIT bit(n);
    for (int i = 1; i <= n; ++i)
        bit.add(i, B[i]);

    // 线段树需要的是|B|
    vector<ll> absB(n + 1);
    for (int i = 1; i <= n; ++i)
        absB[i] = llabs(B[i]);
    SegTree seg(n, absB);

    while (m--) {
        char op;
        cin >> op;
        if (op == 'C') {
            ll l, r, d;
            cin >> l >> r >> d;
            // 更新左端点
            B[l] += d;
            bit.add(l, d);
            seg.update(1, 1, n, l, B[l]);
            // 更新右端点+1（如果存在）
            if (r + 1 <= n) {
                B[r + 1] -= d;
                bit.add(r + 1, -d);
                seg.update(1, 1, n, r + 1, B[r + 1]);
            }
        } else {
            ll l, r;
            cin >> l >> r;
            ll al = bit.sum(l);                  // a[l] 的值
            ll x = llabs(al);                    // 取绝对值
            ll g = seg.query(1, 1, n, l + 1, r); // 差分数组[l+1, r]的gcd
            ll ans = gcd(x, g);
            cout << ans << '\n';
        }
    }

    return 0;
}