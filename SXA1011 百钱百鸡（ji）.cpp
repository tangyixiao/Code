#include <bits/stdc++.h>
using namespace std;

signed main() {
    for (int x = 1; x <= 33; x++) {
        for (int y = 1; y <= 50; y++) {
            int z = 100 - x - y;
            if (z <= 0 || z % 3 != 0) {
                continue;
            }
            if (3 * x + 2 * y + z / 3 == 100) {
                cout << x << " " << y << " " << z << "\n";
            }
        }
    }
    return 0;
}
