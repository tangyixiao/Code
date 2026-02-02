#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, a[N], b[N], ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n - 1; i++) {
        b[i] = a[i + 1] - a[i];
    }
    sort(b + 1, b + n);
    for (int i = 1; i <= k; i++) {
        ans += b[i];
    }
    cout << ans;
    return 0;
}