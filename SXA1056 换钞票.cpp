#include <bits/stdc++.h>
using namespace std;

int a, b;

signed main() {
    for (a = 1; a <= 10; a++) {
        b = (100 - 10 * a) / 20;
        if (10 * a + 20 * b == 100 && b >= 1) {
            cout << a << " " << b << "\n";
        }
    }
    return 0;
}
