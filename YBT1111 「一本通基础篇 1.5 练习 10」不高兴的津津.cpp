#include <bits/stdc++.h>
using namespace std;

int mx, d;

inline void input() {
    return;
}

inline void solve() {
    for (int i = 1; i <= 7; i++) {
        int a, b;
        cin >> a >> b;
        if (a + b > 8 && a + b > mx) {
            mx = a + b, d = i;
        }
    }
    cout << d << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}