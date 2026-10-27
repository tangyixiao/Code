#include <bits/stdc++.h>
using namespace std;

int n, h, t, u;

signed main() {
    cin >> n;
    h = n / 100, t = n / 10 % 10, u = n % 10;
    cout << fixed << setprecision(2) << 1.0 * (h + t) / (t + u) << "\n";
    return 0;
}
