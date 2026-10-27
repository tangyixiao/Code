#include <bits/stdc++.h>
using namespace std;

int a[1005];

signed main() {
    int n, i, mn, mx;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    mn = mx = a[1];
    for (i = 2; i <= n; i++) {
        if (a[i] < mn) {
            mn = a[i];
        }
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    for (i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        if (a[i] == mn) {
            cout << a[i] + 1;
        } else if (a[i] == mx) {
            cout << a[i] * 2;
        } else {
            cout << a[i];
        }
    }
    cout << "\n";
    return 0;
}
