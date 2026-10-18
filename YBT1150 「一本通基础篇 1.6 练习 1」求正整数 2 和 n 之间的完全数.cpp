#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 2; i <= n; i++) {
        int s = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                s += j, s += j == i / j ? 0 : i / j;
            }
        }
        if (s == i) {
            cout << i << "\n";
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}