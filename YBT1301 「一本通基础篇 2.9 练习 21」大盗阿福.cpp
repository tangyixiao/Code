#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T, n, a[N], f[N];

inline void input() {
    cin >> T;
}

inline void solve() {
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = max(f[i - 1], f[i - 2] + a[i]);
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