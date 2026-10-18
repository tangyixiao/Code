#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int d[N] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int y, m, d1;

inline void input() {
    cin >> y >> m >> d1;
}

inline void solve() {
    int ans = d1;
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        d[2] = 29;
    }
    for (int i = 1; i < m; i++) {
        ans += d[i];
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
