#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, a[N], sum[N], res, k;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    if (k + 1 >= n) {
        cout << 0;
        exit(0);
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    res = sum[k];
    for (int i = 2; i <= n - k; i++) {
        res = max(res, sum[i + k - 1] - sum[i - 1]);
    }
    cout << sum[n - 1] - res;
    return 0;
}