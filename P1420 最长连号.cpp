#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, a[N], dp[N];
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
    }
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}