#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

long long f[N], g[N], s[N], n;

inline void input() {
    g[0] = 1;
}

inline void solve() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        g[i] = f[i - 1];
        s[i] = 2 * g[i - 1] + s[i - 1];
        f[i] = g[i] + s[i];
    }
    cout << f[n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
