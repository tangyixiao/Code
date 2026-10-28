#include <bits/stdc++.h>
using namespace std;

int n, x, y;

signed main() {
    cin >> n;
    x = n / 100, y = n % 100;
    cout << x + y << "\n";
    cout << fixed << setprecision(1) << 1.0 * x / y << "\n";
    return 0;
}
