#include <bits/stdc++.h>
using namespace std;

int n, i;
double ax, ay, bx, by, cx0, cy0, gx, gy;

signed main() {
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        for (i = 0; i < n; i++) {
            cin >> ax >> ay >> bx >> by >> cx0 >> cy0;
            gx = (ax + bx + cx0) / 3;
            gy = (ay + by + cy0) / 3;
            cout << fixed << setprecision(1) << gx << " " << gy << "\n";
        }
    }
    return 0;
}
