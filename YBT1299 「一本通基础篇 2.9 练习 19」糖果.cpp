#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, k, a[N], f[N][N];

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    return;
}

inline void solve() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            f[i][j] = -1;
        }
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (f[i - 1][j] >= 0) {
                f[i][j] = max(f[i][j], f[i - 1][j]);
            }
            int t = (j + k - a[i] % k) % k;
            if (f[i - 1][t] >= 0) {
                f[i][j] = max(f[i][j], f[i - 1][t] + a[i]);
            }
        }
    }
    cout << max(f[n][0], 0) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
