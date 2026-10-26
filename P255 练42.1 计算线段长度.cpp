#include <bits/stdc++.h>
using namespace std;

double xa, ya, xb, yb;

signed main() {
    cin >> xa >> ya >> xb >> yb;
    cout << fixed << setprecision(3) << sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) << "\n";
    return 0;
}
