#include <bits/stdc++.h>
using namespace std;

signed main() {
    for (int i = 10000; i <= 99999; i++) {
        long long old = (long long)i * 10 + 7;
        long long nw = 700000LL + i;
        if (nw == 4 * old) {
            cout << old << "\n";
        }
    }
    return 0;
}
