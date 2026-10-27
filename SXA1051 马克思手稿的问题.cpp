#include <bits/stdc++.h>
using namespace std;

signed main() {
    for (int x = 0; x <= 30; x++) {
        for (int y = 0; y <= 30 - x; y++) {
            int z = 30 - x - y;
            if (3 * x + 2 * y + z == 50) {
                cout << x << " " << y << " " << z << "\n";
            }
        }
    }
    return 0;
}
