#include <bits/stdc++.h>
using namespace std;

long long mm, nn, t, x, y, u, v, g;
double ph = (1 + sqrt(5.0)) / 2;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> mm >> nn;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        cin >> x >> y;
        if (x > y) {
            u = y;
            v = x;
        } else {
            u = x;
            v = y;
        }
        g = (long long)((v - u) * ph);
        if (g == u) {
            cout << "Farmer John\n";
        } else {
            cout << "Bessie\n";
        }
    }
    return 0;
}
