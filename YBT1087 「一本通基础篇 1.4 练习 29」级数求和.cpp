#include <bits/stdc++.h>
using namespace std;

double k, s;

inline void input() {
    cin >> k;
    return;
}

inline void solve() {
    for (int i = 1; s <= k; i++) {
        s += 1.0 / i;
        if (s > k) {
            cout << i << "\n";
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