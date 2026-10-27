#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int M = 1e4 + 5;
const int INF = 1e9 + 5;
int h, n, a[N], b[N], dp[M];
signed main() {
    cin >> h >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= h; i++) {
        dp[i] = INF;
    }
    for (int s = 0; s < h; s++) {
        if (dp[s] == INF) {
            continue;
        }
        for (int i = 1; i <= n; i++) {
            int t = s + a[i];
            if (t > h) {
                t = h;
            }
            if (dp[s] + b[i] < dp[t]) {
                dp[t] = dp[s] + b[i];
            }
        }
    }
    cout << dp[h] << "\n";
    return 0;
}
