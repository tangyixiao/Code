#include <bits/stdc++.h>
using namespace std;

int n, h, t, u;

signed main() {
    for (n = 100; n <= 999; n++) {
        h = n / 100, t = n / 10 % 10, u = n % 10;
        if (t > h && t > u) {
            cout << n << "\n";
        }
    }
    return 0;
}
