#include <bits/stdc++.h>
using namespace std;

double c, s, a[5];

signed main() {
    cin >> c >> s >> a[1] >> a[2] >> a[3];
    double t = c / s + a[1] + a[2] + a[3];
    if (t <= 20) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
