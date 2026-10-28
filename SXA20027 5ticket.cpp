#include <bits/stdc++.h>
using namespace std;
signed main() {
    long long p, a, r;
    double d;
    cin >> p >> a;
    if (a <= 6) {
        d = 0;
    } else if (a <= 14) {
        d = p / 2.0;
    } else if (a <= 64) {
        d = p;
    } else {
        d = p / 2.0;
    }
    r = (long long)d;
    if (d == r) {
        cout << r << "\n";
    } else {
        cout << fixed << setprecision(1) << d << "\n";
    }
    return 0;
}
