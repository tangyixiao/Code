#include <bits/stdc++.h>
using namespace std;

double r1, r2;

inline void input() {
    cin >> r1 >> r2;
}

inline void solve() {
    printf("%.2f\n", 1.0 / (1.0 / r1 + 1.0 / r2));
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
