#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N][N], s[N], p[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    int mx = -1e9;
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= n; ++k) {
            s[k] = 0;
        }
        for (int j = i; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                s[k] += a[j][k];
            }
            p[0] = 0;
            for (int k = 1; k <= n; ++k) {
                p[k] = p[k - 1] + s[k];
            }
            int w = 0;
            for (int k = 1; k <= n; ++k) {
                w = min(w, p[k - 1]);
                mx = max(mx, p[k] - w);
            }
        }
    }
    cout << mx << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}