#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415926;
int h, r;

inline void input() {
    cin >> h >> r;
}

inline void solve() {
    printf("%.0f\n", ceil(20000.0 / (PI * r * r * h)));
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
