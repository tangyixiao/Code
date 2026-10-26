#include <bits/stdc++.h>
using namespace std;

int n, i;

signed main() {
    cin >> n;
    if (n == 1) {
        cout << 3 << "\n";
        return 0;
    }
    long long dp[50][3][3];
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j && i != 1) {
                dp[2][i][j] = 1;
            }
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int p = 0; p < 3; p++) {
            for (int q = 0; q < 3; q++) {
                if (p == q || dp[len - 1][p][q] == 0) {
                    continue;
                }
                for (int r = 0; r < 3; r++) {
                    if (r == q) {
                        continue;
                    }
                    if (q == 1) {
                        if (!((p == 0 && r == 2) || (p == 2 && r == 0))) {
                            continue;
                        }
                    }
                    dp[len][q][r] += dp[len - 1][p][q];
                }
            }
        }
    }
    long long ans = 0;
    for (int p = 0; p < 3; p++) {
        for (int q = 0; q < 3; q++) {
            if (q != 1) {
                ans += dp[n][p][q];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
