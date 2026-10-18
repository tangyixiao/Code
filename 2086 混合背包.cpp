#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int v, n, w[N], c[N], p[N], f[N];

inline void input() {
    cin >> v >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> c[i] >> p[i];
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        if (p[i] == 0) {
            for (int j = w[i]; j <= v; ++j) {
                f[j] = max(f[j], f[j - w[i]] + c[i]);
            }
        } else if (p[i] == 1) {
            for (int j = v; j >= w[i]; --j) {
                f[j] = max(f[j], f[j - w[i]] + c[i]);
            }
        } else {
            for (int j = v; j >= w[i]; --j) {
                for (int k = 1; k <= p[i] && k * w[i] <= j; ++k) {
                    f[j] = max(f[j], f[j - k * w[i]] + k * c[i]);
                }
            }
        }
    }
    cout << f[v] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
