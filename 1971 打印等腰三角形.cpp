#include <bits/stdc++.h>
using namespace std;

inline void input() {}

inline void solve() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}