#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n, x, y, a, b;
    cin >> n >> x >> y;
    for (a = 1; a * x <= n; a++) {
        b = (n - a * x) / y;
        if (a * x + b * y == n && b >= 1 && a >= b && a + b >= 5) {
            cout << a << " " << b << "\n";
        }
    }
    return 0;
}
