#include <bits/stdc++.h>
using namespace std;
int n, m, i, x, y, odd, ans;
int dg[100005];
signed main() {
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        dg[x]++;
        dg[y]++;
    }
    odd = 0;
    for (i = 1; i <= n; i++) {
        if (dg[i] % 2 == 1) {
            odd++;
        }
    }
    ans = odd / 2;
    if (ans < 1) {
        ans = 1;
    }
    cout << ans << "\n";
    return 0;
}
