#include <bits/stdc++.h>
using namespace std;
int x, y;
signed main() {
    for (x = 1; x <= 36; x++) {
        for (y = 1; y <= 36; y++) {
            if (7 * x + 5 * y == 36 && x + y <= 35) {
                cout << x << " " << y << " " << 36 - x - y << "\n";
            }
        }
    }
    return 0;
}
