#include <bits/stdc++.h>
using namespace std;

long long a, b, x, y, z;

inline void input() {
    cin >> a >> b;
    cin >> x >> y >> z;
}

inline void solve() {
    input();
    long long p = 2 * x + y - a, q = y + 3 * z - b;
    cout << (p > 0 ? p : 0) + (q > 0 ? q : 0) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}