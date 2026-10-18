#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int T, n, k, m[N], p[N], f[N], g[N];

inline void input() {
    cin >> T;
}

inline void solve() {
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> m[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        for (int i = 0; i <= n; ++i) {
            f[i] = 0;
            g[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            g[i] = 0;
            for (int j = i - 1; j >= 1; --j) {
                if (m[i] - m[j] > k) {
                    g[i] = j;
                    break;
                }
            }
            f[i] = max(f[i - 1], f[g[i]] + p[i]);
        }
        cout << f[n] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}