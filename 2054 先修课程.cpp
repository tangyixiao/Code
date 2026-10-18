#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, h[N], e[N], ne[N], d[N], q[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        ne[i] = h[u], e[i] = v, h[u] = i, d[v]++;
    }
}

inline void solve() {
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            q[r++] = i;
        }
    }
    for (; l < r; l++) {
        for (int i = h[q[l]]; i; i = ne[i]) {
            if (!--d[e[i]]) {
                q[r++] = e[i];
            }
        }
    }
    cout << (r == n ? "Valid" : "Invalid") << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
