#include <bits/stdc++.h>
using namespace std;

int n;

inline void rep(int x, int hi) {
    bool f = 0;
    for (int i = hi; i >= 0; --i) {
        if (!(x >> i & 1)) {
            continue;
        }
        if (f) {
            cout << "+";
        }
        f = 1;
        if (i == 1) {
            cout << "2";
        } else if (i == 0) {
            cout << "2(0)";
        } else {
            cout << "2(";
            int k = 0;
            while (i >> (k + 1)) {
                ++k;
            }
            rep(i, k);
            cout << ")";
        }
    }
}

inline void input() {
    cin >> n;
}

inline void solve() {
    int k = 0;
    while (n >> (k + 1)) {
        ++k;
    }
    rep(n, k);
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
