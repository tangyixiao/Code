#include <bits/stdc++.h>
using namespace std;

int a, b, c;

inline int mx(int x, int y, int z) {
    return max(max(x, y), z);
}

inline void input() {
    cin >> a >> b >> c;
    return;
}

inline void solve() {
    cout << fixed << setprecision(3)
         << 1.0 * mx(a, b, c) / (mx(a + b, b, c) * mx(a, b, b + c)) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}