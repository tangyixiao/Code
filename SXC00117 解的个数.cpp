#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (; t; t--) {
        long long k, kk, c = 0;
        cin >> k;
        kk = k * k;
        for (long long d = 1; d <= k; d++) {
            if (kk % d == 0) {
                c++;
            }
        }
        cout << c << "\n";
        for (long long d = 1; d <= k; d++) {
            if (kk % d == 0) {
                long long y = k + d, x = k + kk / d;
                cout << "1/" << k << " = 1/" << x << " + 1/" << y << "\n";
            }
        }
    }
    return 0;
}
