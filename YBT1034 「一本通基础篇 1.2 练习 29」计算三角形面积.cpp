#include <bits/stdc++.h>
using namespace std;

float x1, b1, x2, y2, x3, y3;

inline void input() {
    cin >> x1 >> b1 >> x2 >> y2 >> x3 >> y3;
}

inline void solve() {
    double s = (x1 * (y2 - y3) + x2 * (y3 - b1) + x3 * (b1 - y2)) / 2.0;
    printf("%.2f\n", s < 0 ? -s : s);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
