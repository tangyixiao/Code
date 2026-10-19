#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5, M = 1e4 + 5;
int n, W, dp[N][M], w[N], v[N], s[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> s[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= s[i] && k * w[i] <= j; k++) {
                if (dp[i - 1][j - k * w[i]] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
                }
            }
        }
    }
    cout << dp[n][W] << "\n";
    return 0;
}