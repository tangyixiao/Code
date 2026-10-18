#include <bits/stdc++.h>
using namespace std;
int x, y, z;

int main() {
    printf("%-5s%-5s%-5s\n", "公鸡", "母鸡", "小鸡");
    for (x = 0; x <= 20; x++) {
        for (y = 1; y <= 33; y++) {
            z = 100 - x - y;
            if (z <= 0) continue;
            if (5 * x + 3 * y + z / 2 != 100) continue;
            if (z % 2 == 1 || z % 4 != 0) continue;
            printf("%-5d%-5d%-5d\n", x, y, z);
        }
    }
    return 0;
}