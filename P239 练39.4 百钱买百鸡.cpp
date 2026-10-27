#include <bits/stdc++.h>
using namespace std;
int x, y, z;

signed main() {
    printf("%-5s%-5s%-5s\n", "\xb9\xab\xbc\xa6", "\xc4\xb8\xbc\xa6", "\xd0\xa1\xbc\xa6");
    for (x = 1; x <= 20; x++) {
        for (y = 1; y <= 39; y++) {
            z = 100 - x - y;
            if (z <= 0) {
                continue;
            }
            if (z % 3 != 0) {
                continue;
            }
            if (3 * x + 2 * y + z / 3 != 100) {
                continue;
            }
            printf("%-5d%-5d%-5d\n", x, y, z);
        }
    }
    return 0;
}
