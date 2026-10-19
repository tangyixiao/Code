#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << j;
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
