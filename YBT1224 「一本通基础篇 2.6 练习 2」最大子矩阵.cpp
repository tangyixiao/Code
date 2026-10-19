#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int a[N][N], s[N], n, ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void solve() {
    ans = -1e9;
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= n; ++k) {
            s[k] = 0;
        }
        for (int j = i; j <= n; ++j) {
            int t = 0;
            for (int k = 1; k <= n; ++k) {
                s[k] += a[j][k];
                t = max(s[k], t + s[k]), ans = max(ans, t);
            }
        }
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
