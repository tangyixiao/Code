#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int m, n;
string a, b;
int f[N], g[N];

inline void input() { cin >> a >> b; }

inline void solve() {
    m = a.size(), n = b.size();
    for (int j = 0; j <= n; ++j) {
        f[j] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        g[0] = 0;
        for (int j = 1; j <= n; ++j) {
            g[j] = g[j - 1];
            if (a[i - 1] == b[j - 1]) {
                g[j] = max(g[j], f[j - 1] + 1);
            } else {
                g[j] = max(g[j], f[j]);
            }
        }
        for (int j = 0; j <= n; ++j) {
            f[j] = g[j];
        }
    }
    cout << f[n] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}