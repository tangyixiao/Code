#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n, k, a[N], b[N], r[N], f[N], g[N], t[N], m;

void upd(int x, int v) {
    for (; x <= m; x += x & -x) {
        t[x] = max(t[x], v);
    }
}

int qry(int x) {
    int s = 0;
    for (; x > 0; x -= x & -x) {
        s = max(s, t[x]);
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
        r[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = qry(r[i] - 1) + 1;
        upd(r[i], f[i]);
    }
    for (int i = 0; i <= m + 1; i++) {
        t[i] = 0;
    }
    for (int i = n; i >= 1; i--) {
        int rr = m + 1 - r[i];
        g[i] = qry(rr - 1) + 1;
        upd(rr, g[i]);
    }
    cout << f[k] + g[k] - 1 << "\n";
    return 0;
}
