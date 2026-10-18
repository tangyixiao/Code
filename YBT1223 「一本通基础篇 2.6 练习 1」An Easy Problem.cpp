#include <bits/stdc++.h>
using namespace std;

int n;

void solve();

inline int g(int x) {
    int c = 0;
    while (x) {
        x &= x - 1, ++c;
    }
    return c;
}

inline void input() {
    while (cin >> n && n) {
        solve();
    }
    return;
}

inline void solve() {
    int c = g(n);
    for (int x = n + 1;; ++x) {
        if (g(x) == c) {
            cout << x << "\n";
            return;
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    return 0;
}
