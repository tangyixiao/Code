#include <bits/stdc++.h>
using namespace std;

int a, b;

inline void input() {
    cin >> a >> b;
}

inline void solve() {
    cout << (a >= 10 || b >= 20) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
