#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int t, n;
long long a[N], f[N], g[N];

inline void input() {
    cin >> t;
    return;
}

inline void solve() {
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            g[i] = a[i];
            if (i > 1) {
                g[i] = max(g[i], g[i - 1] + a[i]);
            }
        }
        for (int i = n; i >= 1; i--) {
            f[i] = a[i];
            if (i < n) {
                f[i] = max(f[i], f[i + 1] + a[i]);
            }
        }
        long long s = -1e18, p = g[1];
        for (int j = 2; j <= n; j++) {
            s = max(s, p + f[j]), p = max(p, g[j]);
        }
        cout << s << "\n";
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