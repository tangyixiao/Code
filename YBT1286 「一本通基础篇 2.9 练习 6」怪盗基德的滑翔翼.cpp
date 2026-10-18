#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int k, n, a[N], f[N], g[N];

inline void input() {
    cin >> k;
    return;
}

inline void solve() {
    while (k--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int r = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = g[i] = 1;
            for (int j = 1; j < i; j++) {
                if (a[j] < a[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
                if (a[j] > a[i]) {
                    g[i] = max(g[i], g[j] + 1);
                }
            }
            r = max(r, max(f[i], g[i]));
        }
        cout << r << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}