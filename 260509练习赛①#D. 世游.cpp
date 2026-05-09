#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m, dp[N][N];
char mp[N][N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (i != n || j != m) {
                dp[i][j] = -1e9;
                dp[i][j] = ((i + 1 <= n) ? (max(dp[i][j], (((mp[i + 1][j] == '+') ? 1 : -1) - dp[i + 1][j]))) : (dp[i][j]));
                dp[i][j] = ((j + 1 <= m) ? (max(dp[i][j], (((mp[i][j + 1] == '+') ? 1 : -1) - dp[i][j + 1]))) : (dp[i][j]));
            }
        }
    }

    if (dp[1][1] > 0) {
        cout << "Takahashi\n";
    } else {
        if (dp[1][1] < 0) {
            cout << "Aoki\n";
        } else {
            cout << "Draw\n";
        }
    }

    return 0;
}