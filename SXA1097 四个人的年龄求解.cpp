#include <bits/stdc++.h>
using namespace std;

signed main() {
    for (int a = 1; a <= 130; a++) {
        for (int d = 0; d <= 130; d++) {
            int b = a + d, c = a + 2 * d, e = a + 3 * d;
            if (e > 130) {
                break;
            }
            if (a + b + c + e != 26) {
                continue;
            }
            if (a * b * c * e == 880) {
                cout << a << " " << b << " " << c << " " << e << "\n";
            }
        }
    }
    return 0;
}
