#include <bits/stdc++.h>
using namespace std;

int n, x, y, ans;

signed main() {
    cin >> n >> x >> y;
    for (int i = 10; i * x <= n; i++) {
        if ((n - i * x) % y == 0 && (n - i * x) / y >= 10) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
