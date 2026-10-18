#include <bits/stdc++.h>
using namespace std;

int m, n, s;

inline void input() {
    cin >> m >> n;
}

inline void solve() {
    for (int i = m + !(m & 1); i <= n; i += 2) {
        s += i;
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
