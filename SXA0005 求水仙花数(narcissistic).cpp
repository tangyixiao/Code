#include <bits/stdc++.h>
using namespace std;
signed main() {
    int i, a, b, c;
    for (i = 100; i <= 999; i++) {
        a = i / 100, b = i / 10 % 10, c = i % 10;
        if (a * a * a + b * b * b + c * c * c == i) {
            cout << i << "\n";
        }
    }
    return 0;
}
