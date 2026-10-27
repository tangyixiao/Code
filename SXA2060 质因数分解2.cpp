#include <bits/stdc++.h>
using namespace std;
int m, n, x, d, t, p;
signed main() {
    cin >> m >> n;
    for (x = m; x <= n; x++) {
        cout << x << "=";
        t = x, p = 0;
        for (d = 2; (long long)d * d <= t; d++) {
            for (; t % d == 0;) {
                if (p) {
                    cout << "*";
                }
                cout << d;
                p = 1;
                t /= d;
            }
        }
        if (t > 1) {
            if (p) {
                cout << "*";
            }
            cout << t;
        }
        cout << "\n";
    }
    return 0;
}
