#include <bits/stdc++.h>
using namespace std;
const int MAXH = 20005;
int h, n, a[1005], b[1005], dp[MAXH], inf = 1e9, m;
int main() {
    freopen("e.in", "r", stdin);
    freopen("e.out", "w", stdout);
    cin >> h >> n;
    m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] > m)
            m = a[i];
    }
    for (int i = 0; i < MAXH; ++i)
        dp[i] = inf;
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; j < h + m; ++j) {
            if (dp[j - a[i]] + b[i] < dp[j])
                dp[j] = dp[j - a[i]] + b[i];
        }
    }
    int ans = inf;
    for (int i = h; i < h + m; ++i)
        if (dp[i] < ans)
            ans = dp[i];
    cout << ans << endl;
    return 0;
}