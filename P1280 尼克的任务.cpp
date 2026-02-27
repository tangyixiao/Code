#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> tasks(n + 2);
    for (int i = 0; i < k; ++i) {
        int p, t;
        cin >> p >> t;
        tasks[p].push_back(t);
    }

    vector<int> dp(n + 2, 0);
    for (int i = n; i >= 1; --i) {
        if (tasks[i].empty()) {
            dp[i] = dp[i + 1] + 1;
        } else {

            for (int t : tasks[i]) {
                dp[i] = max(dp[i], dp[i + t]);
            }
        }
    }

    cout << dp[1] << endl;
    return 0;
}