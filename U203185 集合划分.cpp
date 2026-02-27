#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long total = (long long)N * (N + 1) / 2;
    if (total & 1) {
        cout << 0 << '\n';
        return 0;
    }

    int target = total / 2;
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = target; j >= i; --j) {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[target] / 2 << '\n';

    return 0;
}