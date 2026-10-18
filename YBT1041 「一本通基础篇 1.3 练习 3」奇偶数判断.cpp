#include <bits/stdc++.h>
using namespace std;

int x;

inline void input() {
    cin >> x;
}

inline void solve() {
    cout << ((x & 1) ? "odd" : "even") << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
