#include <iostream>
#include <vector>
using namespace std;

const int MOD = 19650827;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

    
    for (int i = 1; i <= n; ++i)
        dp[i][i][0] = 1; 

    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            
            if (h[l] < h[l + 1])
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][0]) % MOD;
            if (h[l] < h[r])
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][1]) % MOD;
            
            if (h[r] > h[l])
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][0]) % MOD;
            if (h[r] > h[r - 1])
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][1]) % MOD;
        }
    }

    int ans = (dp[1][n][0] + dp[1][n][1]) % MOD;
    cout << ans << '\n';

    return 0;
}