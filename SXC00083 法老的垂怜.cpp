#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
int n, k, a[N], b[N], c[N], t[N];

void upd(int x, int v) {
    for (; x <= n; x += x & -x) {
        t[x] = max(t[x], v);
    }
}

int qry(int x) {
    int r = 0;
    for (; x > 0; x -= x & -x) {
        r = max(r, t[x]);
    }
    return r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i;
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int v = unique(b + 1, b + n + 1) - b - 1;
    for (i = 1; i <= n; i++) {
        c[i] = lower_bound(b + 1, b + v + 1, a[i]) - b;
    }
    int f = 0, g = 0, m;
    for (i = 1; i <= k; i++) {
        if (i == k) {
            f = qry(c[i] - 1) + 1;
        } else if (c[i] < c[k]) {
            upd(c[i], qry(c[i] - 1) + 1);
        }
    }
    for (i = 1; i <= n; i++) {
        t[i] = 0;
    }
    for (i = n; i >= k; i--) {
        m = v - c[i] + 1;
        if (i == k) {
            g = qry(m - 1) + 1;
        } else if (c[i] > c[k]) {
            upd(m, qry(m - 1) + 1);
        }
    }
    cout << f + g - 1 << "\n";
    return 0;
}
