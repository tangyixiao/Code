#include <bits/stdc++.h>
using namespace std;

double r;

inline void input() {
    cin >> r;
}

inline void solve() {
    printf("%.2f\n", 4.0 / 3.0 * 3.14 * r * r * r);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
