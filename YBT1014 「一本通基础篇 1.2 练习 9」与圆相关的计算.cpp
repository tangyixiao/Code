#include <bits/stdc++.h>
using namespace std;

const double P = 3.14159;
double r;

inline void input() {
    cin >> r;
}

inline void solve() {
    cout << fixed << setprecision(4) << 2 * r << " " << 2 * P * r << " " << P * r * r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}