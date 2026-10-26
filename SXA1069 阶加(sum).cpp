#include <bits/stdc++.h>
using namespace std;

int n, i, x, ans;

signed main() {
    cin >> n;
    ans = 0;
    for (i = 1; i <= n; i++) {
        ans += i * (i + 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
