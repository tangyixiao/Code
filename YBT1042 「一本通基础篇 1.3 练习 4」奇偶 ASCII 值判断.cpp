#include <bits/stdc++.h>
using namespace std;

char c;

inline void input() {
    cin >> c;
}

inline void solve() {
    cout << (((int)c & 1) ? "YES" : "NO") << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
