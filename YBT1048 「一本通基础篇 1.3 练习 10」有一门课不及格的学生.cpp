#include <bits/stdc++.h>
using namespace std;

int a, b;

inline void input() {
    cin >> a >> b;
}

inline void solve() {
    cout << ((a < 60) != (b < 60)) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
