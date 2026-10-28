#include <bits/stdc++.h>
using namespace std;

long long x, n, ans, d;

signed main() {
    cin >> x >> n;
    for (long long i = 0; i < n; i++) {
        d = (x - 1 + i) % 7 + 1;
        if (d <= 5) {
            ans += 250;
        }
    }
    cout << ans << "\n";
    return 0;
}
