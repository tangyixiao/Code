#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n, m, s[N], c;

inline void input() {
    cin >> n >> m;
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        s[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= n; j += i) {
            if (i == 1) {
                s[j] = 0;
            } else if (i == 2) {
                s[j] = 1;
            } else {
                s[j] ^= 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!s[i]) {
            c++, cout << (c == 1 ? "" : ",") << i;
        }
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}