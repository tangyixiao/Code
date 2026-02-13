#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, H;
    cin >> N >> H;

    vector<int> P(N), C(N);
    int maxP = 0;
    for (int i = 0; i < N; ++i) {
        cin >> P[i] >> C[i];
        maxP = max(maxP, P[i]);
    }

    int mw = H + maxP;
    vector<long long> dp(mw + 1, LLONG_MAX / 2);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        int w = P[i], v = C[i];

        for (int j = w; j <= mw; ++j) {
            dp[j] = min(dp[j], dp[j - w] + v);
        }
    }

    long long ans = LLONG_MAX;
    for (int j = H; j <= mw; ++j) {
        ans = min(ans, dp[j]);
    }

    cout << ans << "\n";

    return 0;
}