#include <bits/stdc++.h>
using namespace std;
int a, b, x, r;
signed main() {
    for (a = 1; a <= 9; a++) {
        for (b = 0; b <= 9; b++) {
            x = 1100 * a + 11 * b;
            r = (int)(sqrt((double)x) + 0.5);
            if (r * r == x) {
                cout << x << "\n";
            }
        }
    }
    return 0;
}
