#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, i, m, pos, ans;
long long a[N], p[N], v[N];
int mx[4 * N], f[N];
void upd(int o, int l, int r, int x, int val) {
    if (l == r) {
        if (val > mx[o]) {
            mx[o] = val;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid) {
        upd(o * 2, l, mid, x, val);
    } else {
        upd(o * 2 + 1, mid + 1, r, x, val);
    }
    mx[o] = mx[o * 2] > mx[o * 2 + 1] ? mx[o * 2] : mx[o * 2 + 1];
}
int qry(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) {
        return -1;
    }
    if (ql <= l && r <= qr) {
        return mx[o];
    }
    int mid = (l + r) / 2, u = qry(o * 2, l, mid, ql, qr), w = qry(o * 2 + 1, mid + 1, r, ql, qr);
    return u > w ? u : w;
}
signed main() {
    if (fopen("ele.in", "r")) {
        freopen("ele.in", "r", stdin);
        freopen("ele.out", "w", stdout);
    }
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        p[i] = p[i - 1] + a[i];
    }
    for (i = 0; i <= n; i++) {
        v[i] = p[i];
    }
    sort(v, v + n + 1);
    m = unique(v, v + n + 1) - v;
    for (i = 0; i < 4 * (m + 2); i++) {
        mx[i] = -1;
    }
    upd(1, 0, m - 1, 0, 0);
    for (i = 1; i <= n; i++) {
        pos = lower_bound(v, v + m, p[i]) - v;
        int t = qry(1, 0, m - 1, 0, pos);
        if (t < 0) {
            f[i] = -1;
            continue;
        }
        f[i] = t + 1;
        upd(1, 0, m - 1, pos, f[i]);
    }
    ans = n - f[n];
    printf("%d\n", ans);
    return 0;
}
