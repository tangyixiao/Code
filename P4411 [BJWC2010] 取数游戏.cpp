#include <bits/stdc++.h>
using namespace std;
const int V = 1e6 + 5;
int n, l, ans, dp[V], mx, res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l;
    for (int i = 0, x; i < n; i++) {
        vector<int> fac;
        mx = 0;
        cin >> x;
        for (int d = 1; d * d <= x; d++) {
            if (!(x % d)) {
                if (d >= l) {
                    fac.push_back(d);
                }
                if (x / d != d && x / d >= l) {
                    fac.push_back(x / d);
                }
            }
        }
        for (int j = 0; j < fac.size(); j++) {
            int d = fac[j];
            mx = max(mx, dp[d]);
        }
        res = mx + 1;
        for (int j = 0; j < fac.size(); j++) {
            int d = fac[j];
            dp[d] = max(dp[d], res);
        }
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}