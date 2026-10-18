#include <bits/stdc++.h>
using namespace std;

int a, b, c, g;

inline void input() {
    cin >> a >> b >> c;
    return;
}

inline void solve() {
    g = __gcd(abs(a - b), abs(a - c));
    for (int x = 2; x <= g; x++) {
        if (g % x == 0) {
            cout << x << "\n";
            return;
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}