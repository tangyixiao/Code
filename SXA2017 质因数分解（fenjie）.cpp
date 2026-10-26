#include <bits/stdc++.h>
using namespace std;

int n, first = 1;

signed main() {
    cin >> n;
    cout << n << "=";
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (!first) {
                cout << "*";
            }
            first = 0;
            cout << i;
            n /= i;
        }
    }
    if (n > 1) {
        if (!first) {
            cout << "*";
        }
        cout << n;
    }
    cout << "\n";
    return 0;
}
