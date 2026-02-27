#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 55, M = 1300;
int n, m, a[N][N], sum[N][N], dp[N][N][M];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            sum[i][j] = sum[i - 1][j] + a[i][j];
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= n; i++) {
            for (int k = i; k <= m; k++) {
                for (int t = 0; t <= i + 1; t++) {
                    dp[i][j][k] = max(dp[i][j][k], dp[t][j - 1][k - i] + sum[i][j]);
                }
            }
        }
    }
    cout << max(dp[0][n][m], dp[1][n][m]) << "\n";
    return 0;
}
