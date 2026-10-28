#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long x, y;
    cin >> x >> y;
    if (x >= y) {
        cout << 1 << "\n";
        return 0;
    }
    long long k = (y - x) / 2 + 1, f = y - 2 * k;
    long long m0 = y - x + 1;
    if (m0 <= k) {
        cout << m0 << "\n";
        return 0;
    }
    long long sk = k * y - k * (k - 1);
    long long num = sk - k * f, den = x - f;
    long long ans = (num + den - 1) / den;
    if (ans < k) {
        ans = k;
    }
    cout << ans << "\n";
    return 0;
}
