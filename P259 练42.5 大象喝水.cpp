#include <bits/stdc++.h>
using namespace std;

int h, r;

inline void input() {
    cin >> h >> r;
}

inline void solve() {
    const double pi = 3.14159;
    double v = pi * r * r * h;
    cout << (int)ceil(20000 / v) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
