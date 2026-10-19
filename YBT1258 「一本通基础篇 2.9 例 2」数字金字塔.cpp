#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N][N], d[N][N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            d[i][j] = a[i][j] + d[i - 1][j] > a[i][j] + d[i - 1][j - 1] ? a[i][j] + d[i - 1][j] : a[i][j] + d[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
        ans = d[n][j] > ans ? d[n][j] : ans;
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
