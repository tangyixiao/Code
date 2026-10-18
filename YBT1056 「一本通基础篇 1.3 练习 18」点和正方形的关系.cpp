#include <bits/stdc++.h>
using namespace std;

int x, y;

inline void input() {
    cin >> x >> y;
}

inline void solve() {
    cout << ((x >= -1 && x <= 1 && y >= -1 && y <= 1) ? "yes" : "no") << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
