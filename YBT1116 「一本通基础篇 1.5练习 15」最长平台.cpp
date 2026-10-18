#include <bits/stdc++.h>
using namespace std;

int n, t, c, mx;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i && a != t) {
            c = 0;
        }
        t = a, c++;
        if (c > mx) {
            mx = c;
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