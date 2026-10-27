#include <bits/stdc++.h>
using namespace std;
signed main() {
    int m, n, i, ans = 0;
    cin >> m >> n;
    for (i = m; i <= n; i++) {
        if (i % 6 == 0 || i % 8 == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
