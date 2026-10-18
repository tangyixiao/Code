#include <bits/stdc++.h>
using namespace std;

int x, y;

inline void input() {
    cin >> x >> y;
}

inline void solve() {
    while (x != y) {
        if (x > y) {
            x >>= 1;
        } else {
            y >>= 1;
        }
    }
    cout << x << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
