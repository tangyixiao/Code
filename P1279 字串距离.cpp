#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    int K;
    cin >> A >> B >> K;

    int la = (int)A.size();
    int lb = (int)B.size();

    vector<vector<int>> dp(la + 1, vector<int>(lb + 1, 0x3f3f3f3f));
    dp[0][0] = 0;

    for (int i = 1; i <= la; ++i)
        dp[i][0] = i * K;
    for (int j = 1; j <= lb; ++j)
        dp[0][j] = j * K;

    for (int i = 1; i <= la; ++i) {
        for (int j = 1; j <= lb; ++j) {

            int d = abs(A[i - 1] - B[j - 1]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + d);

            dp[i][j] = min(dp[i][j], dp[i - 1][j] + K);

            dp[i][j] = min(dp[i][j], dp[i][j - 1] + K);
        }
    }

    cout << dp[la][lb] << '\n';
    return 0;
}