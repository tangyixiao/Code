#include <bits/stdc++.h>
using namespace std;

int a, n, r;

inline void input() {
    cin >> a >> n;
}

inline void solve() {
    r = 1;
    for (int i = 0; i < n; i++) {
        r *= a;
    }
    cout << r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
