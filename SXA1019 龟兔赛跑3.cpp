#include <bits/stdc++.h>
using namespace std;

signed main() {
    int x, y, t = 1;
    long long a, b;
    cin >> x >> y;
    a = x, b = y;
    for (; a < b;) {
        t++;
        int av = x + (t - 1), bv = y - 2 * (t - 1);
        if (bv < 2) {
            bv = 2;
        }
        a += av, b += bv;
    }
    cout << t << "\n";
    return 0;
}
