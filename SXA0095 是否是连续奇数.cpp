#include <bits/stdc++.h>
using namespace std;
int a[5], i, j, ok, t;
signed main() {
    for (i = 1; i <= 4; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 5);
    ok = 1;
    for (i = 1; i <= 4; i++) {
        if (a[i] % 2 != 1) {
            ok = 0;
        }
    }
    for (i = 2; i <= 4; i++) {
        if (a[i] - a[i - 1] != 2) {
            ok = 0;
        }
    }
    if (ok == 1) {
        for (i = 2; i <= 4; i++) {
            cout << a[i - 1] << "+2=" << a[i] << "\n";
        }
    } else {
        for (i = 4; i >= 1; i--) {
            cout << a[i];
            if (i > 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
