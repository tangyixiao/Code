#include <bits/stdc++.h>
using namespace std;

int x, y;

inline void input() {
    cin >> x >> y;
}

inline void solve() {
    cout << (x > y ? '>' : (x == y ? '=' : '<')) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
