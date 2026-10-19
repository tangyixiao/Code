#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, mx;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (a >= 90 && a <= 140 && b >= 60 && b <= 90) {
            c++, mx = max(mx, c);
        } else {
            c = 0;
        }
    }
    cout << mx << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}