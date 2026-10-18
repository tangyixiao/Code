#include <bits/stdc++.h>
using namespace std;

int n, p;
double x, y, s;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> p;
        s += sqrt(x * x + y * y) / 25 + p * 1.5;
    }
    cout << (int)ceil(s) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}