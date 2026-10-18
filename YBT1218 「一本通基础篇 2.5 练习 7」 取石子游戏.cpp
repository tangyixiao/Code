#include <bits/stdc++.h>
using namespace std;

int a, b;

inline bool win(int x, int y) {
    if (x < y) {
        x ^= y, y ^= x, x ^= y;
    }
    if (!y) {
        return false;
    }
    if (x / y >= 2) {
        return true;
    }
    return !win(y, x % y);
}

inline void solve() {
    cout << (win(a, b) ? "win" : "lose") << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> a >> b && (a || b)) {
        solve();
    }
    return 0;
}
