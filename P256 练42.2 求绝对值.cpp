#include <bits/stdc++.h>
using namespace std;

double x;

inline void input() {
    cin >> x;
}

inline void solve() {
    cout << fixed << setprecision(2) << fabs(x) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
