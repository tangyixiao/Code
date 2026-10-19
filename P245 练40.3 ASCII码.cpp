#include <bits/stdc++.h>
using namespace std;

int t;

inline void input() {
    cin >> t;
}

inline void solve() {
    for (int i = 1; i <= t; ++i) {
        int c;
        cin >> c;
        cout << char(c);
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
