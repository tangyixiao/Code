#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int v, n, a[N], f[N];

inline void input() {
    cin >> v >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int j = 0; j <= v; ++j) {
        f[j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= a[i]; --j) {
            f[j] = max(f[j], f[j - a[i]] + a[i]);
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
