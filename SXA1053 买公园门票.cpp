#include <bits/stdc++.h>
using namespace std;

int a, c;

signed main() {
    for (a = 1; 8 * a <= 40; a++) {
        for (c = 1; 3 * c <= 40; c++) {
            if (8 * a + 3 * c == 40) {
                cout << a << " " << c << "\n";
            }
        }
    }
    return 0;
}
