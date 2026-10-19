#include <bits/stdc++.h>
using namespace std;

int m, n, x, p, e;

inline void input() {
    cin >> m >> n >> x;
}

inline void solve() {
    p = n, e = 0;
    for (; m / p;) {
        int c = (m + p - 1) / p;
        if (e + c > x) {
            break;
        }
        e += c, p += m / p;
    }
    cout << p << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
