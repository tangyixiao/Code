#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n, a[N];
long long f[N][N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i], a[i + n] = a[i];
    }
}

inline void solve() {
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i + l - 1 <= 2 * n; ++i) {
            int j = i + l - 1;
            for (int k = i; k < j; ++k) {
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + 1LL * a[i] * a[k + 1] * a[j + 1]);
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, f[i][i + n - 1]);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}