#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, v[N], t[N];

inline void solve() {
    double d = 1e18;
    for (int i = 1; i <= n; ++i) {
        if (t[i] >= 0) {
            d = min(d, t[i] + 4500.0 * 3.6 / v[i]);
        }
    }
    cout << (int)ceil(d) << "\n";
    return;
}

inline void input() {
    while (cin >> n && n) {
        for (int i = 1; i <= n; ++i) {
            cin >> v[i] >> t[i];
        }
        solve();
    }
}

signed main() {
    input();
    return 0;
}