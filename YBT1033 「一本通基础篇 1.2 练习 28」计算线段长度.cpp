#include <bits/stdc++.h>
using namespace std;

double x1, b1, x2, y2;

inline void input() {
    cin >> x1 >> b1 >> x2 >> y2;
}

inline void solve() {
    printf("%.3f\n", sqrt((x1 - x2) * (x1 - x2) + (b1 - y2) * (b1 - y2)));
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
