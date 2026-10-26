#include <bits/stdc++.h>
using namespace std;
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, x, neg = 0, ans = 0;
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> x;
            if (x == -1) {
                neg++;
            }
        }
        while (neg % 2 == 1 || n - 2 * neg < 0) {
            neg--, ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
