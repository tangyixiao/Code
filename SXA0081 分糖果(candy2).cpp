#include <bits/stdc++.h>
using namespace std;
int a[10], i, t, l, r;
signed main() {
    for (i = 1; i <= 5; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= 5; i++) {
        t = a[i] / 3;
        l = i - 1;
        if (l == 0) {
            l = 5;
        }
        r = i + 1;
        if (r == 6) {
            r = 1;
        }
        a[l] += t;
        a[r] += t;
        a[i] = t;
    }
    for (i = 1; i <= 5; i++) {
        cout << setw(5) << a[i];
    }
    cout << "\n";
    return 0;
}
