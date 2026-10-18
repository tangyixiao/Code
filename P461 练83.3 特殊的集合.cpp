#include <bits/stdc++.h>
using namespace std;

long long n, ans;

signed main() {
    cin >> n;
    for (long long d = 1; d <= n; d *= 4) {
        ans += n / d - n / (2 * d);
    }
    cout << ans << "\n";
    return 0;
}
