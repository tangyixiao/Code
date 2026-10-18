#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << i;
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