#include <bits/stdc++.h>
using namespace std;

double x, a, y, b;

inline void input() {
    cin >> x >> a >> y >> b;
}

inline void solve() {
    printf("%.2f\n", (b * y - a * x) / (b - a));
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
