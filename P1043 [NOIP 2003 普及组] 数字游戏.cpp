#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[2025][20], a[2025], f[2025][20];
int n, m, ans = -1e9, now = 2e9;

signed main() {
    queue<int> q;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        q.push(a[i]);
    }
    for (int _ = 1; _ <= n; ++_) {
        for (int i = 1; i <= n; ++i) {
            int x = q.front();
            q.pop();
            a[i] = x;
            q.push(x);
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = -1e9, f[i][j] = 1e9;
            }
        }
        for (int i = 1; i <= n; ++i) {
            a[i] += a[i - 1];
            a[i] = (a[i] + 1000000000) % 10;
            f[i][1] = dp[i][1] = (a[i] + 1000000000) % 10;
        }
        for (int j = 2; j <= m; ++j) {
            for (int i = j; i <= n; ++i) {
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] * ((a[i] - a[k] + 1000000000) % 10));
                    f[i][j] = min(f[i][j], f[k][j - 1] * ((a[i] - a[k] + 1000000000) % 10));
                }
            }
        }
        ans = max(ans, dp[n][m]);
        now = min(now, f[n][m]);
        int x = q.front();
        q.pop();
        q.push(x);
    }
    cout << now << '\n'
         << ans;
    return 0;
}
