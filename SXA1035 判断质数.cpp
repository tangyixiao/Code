#include <bits/stdc++.h>
using namespace std;
int n, i, ok;
signed main() {
    cin >> n;
    ok = 1;
    for (i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            ok = 0;
            cout << i << "\n";
            break;
        }
    }
    if (ok == 1) {
        cout << "Yes\n";
    }
    return 0;
}
