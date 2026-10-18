#include <bits/stdc++.h>
using namespace std;

long long x, y, z, ans = 1;

signed main() {
    cin >> x >> y;
    if (y % x) {
        cout << 0 << "\n";
        return 0;
    }
    z = y / x;
    for (long long i = 2; i * i <= z; i++) {
        if (z % i == 0) {
            int c = 0;
            for (; z % i == 0; z /= i) {
                c++;
            }
            for (int t = 1; t < c; t++) {
                ans *= 2;
            }
        }
    }
    if (z > 1) {
        ans *= 2;
    }
    cout << ans << "\n";
    return 0;
}
