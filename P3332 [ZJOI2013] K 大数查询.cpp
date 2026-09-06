#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
const int N = 5e4 + 5;

struct Node {
    int op, l, r, id;
    long long c;
} a[N], b[N];

int n, m, cnt, ans[N];
long long tr[N << 2], tag[N << 2];
bool go[N];

void push(int p, int l, int r) {
    if (!tag[p] || l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    tr[p << 1] += tag[p] * (mid - l + 1);
    tr[p << 1 | 1] += tag[p] * (r - mid);
    tag[p << 1] += tag[p];
    tag[p << 1 | 1] += tag[p];
    tag[p] = 0;
}

void add(int p, int l, int r, int ql, int qr, long long v) {
    if (ql <= l && r <= qr) {
        tr[p] += v * (r - l + 1);
        tag[p] += v;
        return;
    }
    push(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) {
        add(p << 1, l, mid, ql, qr, v);
    }
    if (qr > mid) {
        add(p << 1 | 1, mid + 1, r, ql, qr, v);
    }
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
}

long long ask(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tr[p];
    }
    push(p, l, r);
    int mid = (l + r) >> 1;
    long long res = 0;
    if (ql <= mid) {
        res += ask(p << 1, l, mid, ql, qr);
    }
    if (qr > mid) {
        res += ask(p << 1 | 1, mid + 1, r, ql, qr);
    }
    return res;
}

void solve(int ql, int qr, int vl, int vr) {
    if (ql > qr) {
        return;
    }
    if (vl == vr) {
        for (int i = ql; i <= qr; i++) {
            if (a[i].op == 2) {
                ans[a[i].id] = vl;
            }
        }
        return;
    }

    int mid = vl + (vr - vl + 1) / 2;

    for (int i = ql; i <= qr; i++) {
        if (a[i].op == 1) {
            if (a[i].c >= mid) {
                add(1, 1, n, a[i].l, a[i].r, 1);
                go[i] = 1;
            } else {
                go[i] = 0;
            }
        } else {
            long long x = ask(1, 1, n, a[i].l, a[i].r);
            if (x >= a[i].c) {
                go[i] = 1;
            } else {
                a[i].c -= x;
                go[i] = 0;
            }
        }
    }

    for (int i = ql; i <= qr; i++) {
        if (a[i].op == 1 && a[i].c >= mid) {
            add(1, 1, n, a[i].l, a[i].r, -1);
        }
    }

    int p = ql;
    for (int i = ql; i <= qr; i++) {
        if (!go[i]) {
            b[p++] = a[i];
        }
    }
    int k = p - 1;
    for (int i = ql; i <= qr; i++) {
        if (go[i]) {
            b[p++] = a[i];
        }
    }
    for (int i = ql; i <= qr; i++) {
        a[i] = b[i];
    }

    solve(ql, k, vl, mid - 1);
    solve(k + 1, qr, mid, vr);
}
} // namespace TANGYIXIAO

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using namespace TANGYIXIAO;

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].op >> a[i].l >> a[i].r >> a[i].c;
        if (a[i].op == 2) {
            a[i].id = ++cnt;
        }
    }

    solve(1, m, -n, n);

    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}