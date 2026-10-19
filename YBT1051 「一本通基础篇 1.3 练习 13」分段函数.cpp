#include <bits/stdc++.h>
using namespace std;

double x;

inline void input() {
    cin >> x;
}

inline void solve() {
    double y;
    if (x < 5) {
        y = -x + 2.5;
    } else if (x < 10) {
        y = 2 - 1.5 * (x - 3) * (x - 3);
    } else {
        y = x / 2 - 1.5;
    }
    cout << fixed << setprecision(3) << y << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}