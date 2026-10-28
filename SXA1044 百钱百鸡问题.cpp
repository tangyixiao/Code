#include <bits/stdc++.h>
using namespace std;

int x, y, z;

signed main() {
    for (x = 1; x <= 20; x++) {
        for (y = 34; y >= 1; y--) {
            z = 100 - x - y;
            if (z > 0 && z % 3 == 0 && 5 * x + 3 * y + z / 3 == 100) {
                cout << x << " " << y << " " << z << "\n";
            }
        }
    }
    return 0;
}
