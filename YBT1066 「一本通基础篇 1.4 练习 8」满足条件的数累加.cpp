#include <bits/stdc++.h>
using namespace std;

int m, n, s;

inline void input() {
    cin >> m >> n;
}

inline void solve() {
    for (int i = m; i <= n; i++) {
        if (i % 17 == 0) {
            s += i;
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
