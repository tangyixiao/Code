#include <bits/stdc++.h>
using namespace std;
int n, i;
double x1, y1, x2, y2, x3, y3, cx, cy;
signed main() {
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        for (i = 0; i < n; i++) {
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            cx = (x1 + x2 + x3) / 3;
            cy = (y1 + y2 + y3) / 3;
            cout << fixed << setprecision(1) << cx << " " << cy << "\n";
        }
    }
    return 0;
}
