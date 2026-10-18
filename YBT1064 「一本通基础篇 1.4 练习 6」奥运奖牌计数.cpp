#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, x, y, z;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        a += x;
        b += y;
        c += z;
    }
    cout << a << " " << b << " " << c << " " << a + b + c << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
