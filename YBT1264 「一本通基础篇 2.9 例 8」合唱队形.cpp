#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, h[N], f[N], g[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (h[j] < h[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j > i; j--) {
            if (h[j] < h[i]) {
                g[i] = max(g[i], g[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i] + g[i] - 1);
    }
    cout << n - ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}