#include <bits/stdc++.h>
using namespace std;

int x, y, z, mx, mn;

signed main() {
    cin >> x >> y >> z;
    mx = max(x, max(y, z)), mn = min(x, min(y, z));
    cout << mx + mn << "\n";
    cout << fixed << setprecision(1) << (mx + mn) / 2.0 << "\n";
    return 0;
}
