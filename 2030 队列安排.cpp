#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, x, k, p, q[N], a[N];

inline void input() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> k >> p;
        if (p) {
            a[i] = k, q[i] = q[k], a[q[i]] = i, q[k] = i;
        } else {
            a[i] = a[k], q[i] = k, q[a[i]] = i, a[k] = i;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        q[a[x]] = q[x], a[q[x]] = a[x];
    }
}

inline void solve() {
    for (int x = q[0]; x; x = q[x]) {
        cout << x << (q[x] ? " " : "\n");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
