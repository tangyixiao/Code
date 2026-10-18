#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int t, m, tt[N], v[N], f[N];

inline void input() {
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> tt[i] >> v[i];
    }
    return;
}

inline void solve() {
    for (int i = 0; i <= t; i++) {
        f[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= tt[i]; j--) {
            f[j] = max(f[j], f[j - tt[i]] + v[i]);
        }
    }
    cout << f[t] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}