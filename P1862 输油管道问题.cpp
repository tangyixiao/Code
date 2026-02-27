#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, a[N], ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = n / 2;
    for (int i = 1; i <= l; i++) {
        ans += (a[n - i + 1] - a[i]);
    }
    cout << ans;
    return 0;
}