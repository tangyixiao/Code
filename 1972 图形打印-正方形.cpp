#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n;

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
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