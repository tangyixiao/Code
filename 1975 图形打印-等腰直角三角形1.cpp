#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            cout << '@';
        }
        cout << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
