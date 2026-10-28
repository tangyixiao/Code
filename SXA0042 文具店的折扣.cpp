#include <bits/stdc++.h>
using namespace std;

double x, y, n;

signed main() {
    cin >> x >> y >> n;
    cout << fixed << setprecision(1) << n - (x + y) * 0.9 << "\n";
    return 0;
}
