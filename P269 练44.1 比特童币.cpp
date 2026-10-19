#include <bits/stdc++.h>
using namespace std;

char b[5];

inline void input() {}

inline void solve() {
    for (int i = 0; i < 16; i++) {
        for (int j = 3; j >= 0; j--) {
            b[j] = char('0' + ((i >> (3 - j)) & 1));
        }
        b[4] = '\0';
        printf("%sB %d\n", b, i);
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}