#include <bits/stdc++.h>
using namespace std;

int x, y, t, r, T, R, i;

signed main() {
    cin >> x >> y;
    r = y;
    for (i = 1; i <= 6e1; i++) {
        t = x + i - 1;
        if (i > 1 && r - 1 >= t) {
            r--;
        }
        if (i > 1 && t >= R - T) {
            cout << i << "\n";
            return 0;
        }
        T += t;
        R += r;
    }
    cout << "Fail\n";
    return 0;
}