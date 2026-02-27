#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans = 0x7fffffff;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        ans = min(ans, a + 7 * b - 6);
    }
    cout << ans;
    return 0;
}