#include <bits/stdc++.h>
using namespace std;

double f;

inline void input() {
    cin >> f;
}

inline void solve() {
    printf("%.5f\n", 5.0 * (f - 32) / 9);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
