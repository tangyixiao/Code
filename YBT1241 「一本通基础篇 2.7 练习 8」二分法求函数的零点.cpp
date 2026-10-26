#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x * x * x - 15 * x * x * x * x + 85 * x * x * x - 225 * x * x + 274 * x - 121;
}

double l = 1.5, r = 2.4, m;

signed main() {
    for (int i = 1; i <= 100; i++) {
        m = (l + r) / 2;
        if (f(m) > 0) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << fixed << setprecision(6) << (l + r) / 2 << "\n";
    return 0;
}
