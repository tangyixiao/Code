#include <bits/stdc++.h>
using namespace std;

int n, i, f;

signed main() {
    cin >> n;
    f = 0;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            f = 1;
        }
    }
    if (n < 2) {
        f = 1;
    }
    if (f == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
