#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, j;

signed main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> m;
        int ans = 0;
        for (k = 0; 5 * k <= m; k++) {
            j = m - n - 4 * k;
            if (j >= 0 && j + k <= n) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
