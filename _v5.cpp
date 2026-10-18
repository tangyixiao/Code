#include <bits/stdc++.h>
using namespace std;
int x, y, z;

int main() {
    printf("\xb9\xab\xbc\xa6  \xc4\xb8\xbc\xa6  \xd0\xa1\xbc\xa6\n");
    for (x = 1; x <= 20; x++) {
        for (y = 1; y <= 39; y++) {
            z = 100 - x - y;
            if (3 * x + 2 * y + z / 3 != 100 || z % 3 != 0) {
                continue;
            }
            printf("%-6d%-6d%-6d\n", x, y, z);
        }
    }
    return 0;
}