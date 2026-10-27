#include <bits/stdc++.h>
using namespace std;

int x, y, z, s;

signed main() {
    cin >> x >> y >> z;
    s = x + y + z;
    cout << s << "\n";
    cout << fixed << setprecision(1) << s / 3.0 << "\n";
    return 0;
}
