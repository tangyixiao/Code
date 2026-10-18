#include <bits/stdc++.h>
using namespace std;

int x, n;

inline void input() {
    cin >> x >> n;
}

inline void solve() {
    cout << (x - 1 + n) % 7 + 1 << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}