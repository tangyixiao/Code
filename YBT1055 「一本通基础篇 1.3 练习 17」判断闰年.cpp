#include <bits/stdc++.h>
using namespace std;

int a;

inline void input() {
    cin >> a;
}

inline void solve() {
    cout << (((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) ? "Y" : "N") << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
