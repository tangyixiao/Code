#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * (n - i) + 1; ++j) {
            cout << "*";
        }
        cout << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}