#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int m, n, w[N], c[N], f[N];

inline void input() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + c[i]);
        }
    }
    cout << f[m] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
