#include <bits/stdc++.h>
using namespace std;
int h;
double r, s;
signed main() {
    cin >> h >> r;
    if (h <= 40) {
        s = h * r;
    } else if (h <= 50) {
        s = 40 * r + (h - 40) * 1.5 * r;
    } else {
        s = 40 * r + 10 * 1.5 * r + (h - 50) * 2.0 * r;
    }
    cout << fixed << setprecision(2) << s << "\n";
    return 0;
}
