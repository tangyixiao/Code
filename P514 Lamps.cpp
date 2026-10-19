#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, k;
char a[N][N];

inline void input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = 0, u = 0;
        for (int j = 1; j <= m; ++j) {
            t += a[i][j] == '0';
        }
        if (t > k || (k - t) & 1) {
            continue;
        }
        for (int j = 1; j <= n; ++j) {
            u += !strcmp(a[i], a[j]);
        }
        ans = max(ans, u);
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