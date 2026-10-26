#include <bits/stdc++.h>
using namespace std;

signed main() {
    for (int x = 0; x <= 33; x++) {
        for (int y = 0; y <= 50; y++) {
            int z = 100 - x - y;
            if (z < 0 || z % 3 != 0) {
                continue;
            }
            if (3 * x + 2 * y + z / 3 == 100) {
                cout << x << " " << y << " " << z << "\n";
            }
        }
    }
    return 0;
}
