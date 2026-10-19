#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int x, y, z;
__int128 e[N], a[N];

inline void input() {
    cin >> x >> y >> z;
}

inline void pr(__int128 v) {
    string s;
    for (; v; v /= 10) {
        s = char('0' + v % 10) + s;
    }
    cout << s << "\n";
    return;
}

inline void solve() {
    a[0] = 1;
    for (int m = 1; m <= z; m++) {
        e[m] = m >= x ? (__int128)y * a[m - x] : 0;
        a[m] = a[m - 1] + (m >= 2 ? e[m - 2] : 0);
    }
    pr(a[z]);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
