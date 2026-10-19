#include <bits/stdc++.h>
using namespace std;

int a, b, n, x, r;

inline void input() { cin >> a >> b >> n; }

inline void solve() {
    x = a % b;
    for (int i = 1; i < n; ++i) {
        x = x % b * 10 % b;
    }
    r = x * 10 / b;
    cout << r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}