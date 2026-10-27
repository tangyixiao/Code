#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, tot;
signed main() {
    for (i = 10; i <= 99; i++) {
        int f = 1;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                f = 0;
            }
        }
        int r = i % 10 * 10 + i / 10;
        for (j = 2; j * j <= r; j++) {
            if (r % j == 0) {
                f = 0;
            }
        }
        if (f) {
            cout << i << "\n";
        }
    }
    return 0;
}
