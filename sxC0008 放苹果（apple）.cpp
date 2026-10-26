#include <bits/stdc++.h>
using namespace std;
int t, M, N, i, j;
int dp[15][15];
signed main() {
    cin >> t;
    for (i = 0; i <= 10; i++) {
        dp[0][i] = 1;
    }
    for (i = 1; i <= 10; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (i = 1; i <= 10; i++) {
        for (j = 2; j <= 10; j++) {
            if (i < j) {
                dp[i][j] = dp[i][i];
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            }
        }
    }
    while (t--) {
        cin >> M >> N;
        cout << dp[M][N] << "\n";
    }
    return 0;
}
