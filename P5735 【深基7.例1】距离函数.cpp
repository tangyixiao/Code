#include <bits/stdc++.h>
using namespace std;
long double xa, ya, xb, yb, xc, yc;
long double dis(long double xx, long double xy, long double yx, long double yy) {
    return sqrt((xx - yx) * (xx - yx) + (xy - yy) * (xy - yy));
}
signed main() {
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    cout << fixed << setprecision(2) << dis(xa, ya, xb, yb) + dis(xb, yb, xc, yc) + dis(xc, yc, xa, ya) << "\n";
    return 0;
}
