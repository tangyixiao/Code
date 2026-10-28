#include <bits/stdc++.h>
using namespace std;

int t, x, y, g;

int gcd(int a, int b) {
    for (; b;) {
        int r = a % b;
        a = b, b = r;
    }
    return a;
}

signed main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> x >> y;
        g = gcd(x, y);
        cout << x / g << " " << y / g << "\n";
    }
    return 0;
}
