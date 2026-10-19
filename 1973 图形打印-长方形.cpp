#include <bits/stdc++.h>
using namespace std;

int n, m;

inline void input() {
    cin >> n >> m;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << "@";
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
