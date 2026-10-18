#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T, n, a[N];
long long f, g, mn, r;

inline void input() {
    cin >> T;
}

inline void solve() {
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        f = g = 0;
        mn = 1e9;
        r = -1e9;
        for (int i = 1; i <= n; ++i) {
            f = max(f, (long long)a[i] - mn);
            mn = min(mn, (long long)a[i]);
            r = max(r, f - a[i]);
            g = max(g, r + a[i]);
        }
        cout << g << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}