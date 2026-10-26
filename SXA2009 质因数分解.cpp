#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    cout << n << "=";
    int f = 1;
    for (int p = 2; p * p <= n; p++) {
        for (; n % p == 0; n /= p) {
            if (!f) {
                cout << "*";
            }
            cout << p;
            f = 0;
        }
    }
    if (n > 1) {
        if (!f) {
            cout << "*";
        }
        cout << n;
    }
    cout << "\n";
    return 0;
}
