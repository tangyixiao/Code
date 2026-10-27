#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a = 0, b = 0;
    for (int i = 1; i <= 1000; i++) {
        int o = 0, z = 0, x = i;
        for (; x; x >>= 1) {
            if (x & 1) {
                o++;
            } else {
                z++;
            }
        }
        if (o > z) {
            a++;
        } else {
            b++;
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}
