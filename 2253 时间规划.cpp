#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

inline void input() {
    cin >> a >> b >> c >> d;
}

inline void solve() {
    cout << (c * 60 + d) - (a * 60 + b) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}