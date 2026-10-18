#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, w[N], d[N], h[N], p[N], f[N], ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> d[i] >> h[i];
        p[i] = i;
    }
}

inline void solve() {
    sort(p + 1, p + n + 1, [](int x, int y) {
        return w[x] != w[y] ? w[x] < w[y] : d[x] != d[y] ? d[x] < d[y]
                                                         : h[x] < h[y];
    });
    for (int i = 1; i <= n; i++) {
        int u = p[i];
        f[u] = h[u];
        for (int j = 1; j < i; j++) {
            int v = p[j];
            if (w[v] <= w[u] && d[v] <= d[u] && h[v] <= h[u]) {
                f[u] = max(f[u], f[v] + h[u]);
            }
        }
        ans = max(ans, f[u]);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
