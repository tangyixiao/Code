#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    cin >> n;
    cout << n << "=";
    int first = 1;
    for (int i = 2; 1LL * i * i <= n; i++) {
        while (n % i == 0) {
            if (!first) {
                cout << "*";
            }
            cout << i;
            first = 0;
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
