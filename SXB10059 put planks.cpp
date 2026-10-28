#include <bits/stdc++.h>
using namespace std;

signed main() {
    int t, i;
    long long n, k1, k2, w, b;
    cin >> t;
    for (i = 1; i <= t; i++) {
        cin >> n >> k1 >> k2;
        cin >> w >> b;
        if (w <= (k1 + k2) / 2 && b <= (2 * n - k1 - k2) / 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
