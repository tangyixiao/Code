#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, ans, cnt;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int x = 3; cnt < n; x++) {
        if (x == 4 || x % 4 == 2) {
            continue;
        }
        cnt++, ans = x;
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
