#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, a = 0, b = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c1 = 0, c0 = 0;
        for (int x = i; x; x >>= 1) {
            if (x & 1) {
                c1++;
            } else {
                c0++;
            }
        }
        if (c1 > c0) {
            a++;
        } else {
            b++;
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}
