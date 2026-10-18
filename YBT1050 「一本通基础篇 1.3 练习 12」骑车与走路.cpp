#include <bits/stdc++.h>
using namespace std;

int d;

inline void input() {
    cin >> d;
}

inline void solve() {
    double a = 50.0 / 3.0, b = (double)d / 1.2;
    if (a < b) {
        cout << "Bike\n";
    } else if (a > b) {
        cout << "Walk\n";
    } else {
        cout << "All\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
