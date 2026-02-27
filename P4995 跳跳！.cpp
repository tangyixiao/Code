#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e2 + 5;
int n, a[N], ans, l, r;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (r = n; l < r;) {
        ans += ((a[r] - a[l]) * (a[r] - a[l++]));
        ans += ((a[r] - a[l]) * (a[r--] - a[l]));
    }
    cout << ans;
    return 0;
}