#include <bits/stdc++.h>
using namespace std;

int a[8];

signed main() {
    for (int i = 1; i <= 7; i++) {
        cin >> a[i];
    }
    int s = 0, mx = 0, mn = 1e9;
    for (int i = 1; i <= 7; i++) {
        s += a[i];
        if (a[i] > mx) {
            mx = a[i];
        }
        if (a[i] < mn) {
            mn = a[i];
        }
    }
    cout << fixed << setprecision(1) << 1.0 * s / 7 << " " << mx << " " << mn << "\n";
    return 0;
}
