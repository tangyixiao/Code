#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int m, n, i, p;
long long a[N], b, ans;
signed main() {
    cin >> m >> n;
    for (i = 1; i <= m; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1);
    for (i = 1; i <= n; i++) {
        cin >> b;
        p = lower_bound(a + 1, a + m + 1, b) - a;
        long long best = 1e18;
        if (p <= m) {
            best = min(best, a[p] - b);
        }
        if (p > 1) {
            best = min(best, b - a[p - 1]);
        }
        ans += best;
    }
    cout << ans << "\n";
    return 0;
}
