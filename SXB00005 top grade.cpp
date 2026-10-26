#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, a[N], ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= m; i++) {
        ans += a[i];
    }
    cout << ans << "\n";
    return 0;
}
