#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    int ans = 0;

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        dp[i][i] = a[i];
        ans = max(ans, a[i]);
    }

    for (int len = 2; len <= N; ++len) {
        for (int i = 1; i + len - 1 <= N; ++i) {
            int j = i + len - 1;

            for (int k = i; k < j; ++k) {
                if (dp[i][k] != 0 && dp[k + 1][j] != 0 && dp[i][k] == dp[k + 1][j]) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}