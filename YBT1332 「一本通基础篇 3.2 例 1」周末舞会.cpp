#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int x, y, n;

inline void input() {
    cin >> x >> y >> n;
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        cout << (i - 1) % x + 1 << " " << (i - 1) % y + 1 << "\n";
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