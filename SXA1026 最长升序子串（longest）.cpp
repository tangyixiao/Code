#include <bits/stdc++.h>
using namespace std;

int n, x, last, cur, ans = 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    last = -1;
    for (int i = 1; i <= n; i++) {
        if (!(cin >> x)) {
            break;
        }
        if (x > last) {
            cur++;
        } else {
            cur = 1;
        }
        last = x;
        ans = max(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}
