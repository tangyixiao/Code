#include <bits/stdc++.h>
using namespace std;

int a;

inline void input() {
    cin >> a;
}

inline void solve() {
    cout << (a & -a) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
