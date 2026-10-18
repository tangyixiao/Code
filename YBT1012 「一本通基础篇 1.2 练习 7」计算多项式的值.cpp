#include <bits/stdc++.h>
using namespace std;

double x, a, b, c, d;

inline void input() {
    cin >> x >> a >> b >> c >> d;
}

inline void solve() {
    printf("%.7f\n", ((a * x + b) * x + c) * x + d);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
