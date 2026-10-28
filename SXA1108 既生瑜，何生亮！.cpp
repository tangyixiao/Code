#include <bits/stdc++.h>
using namespace std;

int d[15];

signed main() {
    int x, y, i, t, v, j, f;
    cin >> x >> y;
    for (i = x; i <= y; i++) {
        t = i * i;
        if (t < 1000000 || t > 9999999) {
            continue;
        }
        for (j = 0; j < 10; j++) {
            d[j] = 0;
        }
        f = 1;
        for (; t > 0;) {
            v = t % 10;
            if (d[v]) {
                f = 0;
            }
            d[v] = 1;
            t /= 10;
        }
        if (f) {
            cout << i << "\n";
        }
    }
    return 0;
}
