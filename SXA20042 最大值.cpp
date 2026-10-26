#include <bits/stdc++.h>
using namespace std;

int n, x, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (i == 1) {
            ans = x;
        }
        ans = max(ans, x);
    }
    cout << ans << "\n";
    return 0;
}
