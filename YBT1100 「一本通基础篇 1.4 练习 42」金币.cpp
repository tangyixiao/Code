#include <bits/stdc++.h>
using namespace std;

int n, d, s;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (d = 1; n > 0; d++) {
        for (int i = 0; i < d && n > 0; i++) {
            s += d, n--;
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