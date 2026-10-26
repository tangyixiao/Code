#include <bits/stdc++.h>
using namespace std;
int n, t, y, w, o;
signed main() {
    cin >> n;
    for (t = 1; t <= 10; t++) {
        for (y = 1; y <= 20; y++) {
            w = 100 - n - 9 * t - 4 * y;
            o = n - t - y - w;
            if (w >= 1 && o >= 1) {
                if (10 * t + 5 * y + 2 * w + o == 100) {
                    cout << t << " " << y << " " << w << " " << o << "\n";
                }
            }
        }
    }
    return 0;
}
