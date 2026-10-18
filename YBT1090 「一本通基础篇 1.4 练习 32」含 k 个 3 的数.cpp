#include <bits/stdc++.h>
using namespace std;

int m, k, c;

inline void input() {
    cin >> m >> k;
}

inline void solve() {
    for (int x = m; x; x /= 10) {
        c += x % 10 == 3;
    }
    cout << (m % 19 == 0 && c == k ? "YES\n" : "NO\n");
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
