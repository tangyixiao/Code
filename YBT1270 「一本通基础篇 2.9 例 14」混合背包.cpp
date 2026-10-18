#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int m, n, f[N];

inline void input() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int w, c, p;
        cin >> w >> c >> p;
        if (p == 0) {
            for (int j = w; j <= m; j++) {
                f[j] = max(f[j], f[j - w] + c);
            }
        } else if (p == 1) {
            for (int j = m; j >= w; j--) {
                f[j] = max(f[j], f[j - w] + c);
            }
        } else {
            for (int j = m; j >= w; j--) {
                for (int k = 1; k <= p && k * w <= j; k++) {
                    f[j] = max(f[j], f[j - k * w] + k * c);
                }
            }
        }
    }
    return;
}

inline void solve() {
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
