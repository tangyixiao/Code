#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    long long cr = 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);
    if (cr == 0) {
        cout << "No" << "\n";
        return 0;
    }
    double a = sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
    double b = sqrt(1.0 * (x2 - x3) * (x2 - x3) + 1.0 * (y2 - y3) * (y2 - y3));
    double c = sqrt(1.0 * (x1 - x3) * (x1 - x3) + 1.0 * (y1 - y3) * (y1 - y3));
    cout << fixed << setprecision(2) << a + b + c << "\n";
    return 0;
}
