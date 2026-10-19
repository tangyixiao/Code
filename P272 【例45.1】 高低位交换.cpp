#include <bits/stdc++.h>
using namespace std;

unsigned int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    cout << ((n << 16) | (n >> 16)) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
