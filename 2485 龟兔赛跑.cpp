#include <bits/stdc++.h>
using namespace std;

long long x, y, t;

inline void input() {
    cin >> x >> y >> t;
}

inline void solve() {
    input();
    cout << t * x * y / (y - x) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}