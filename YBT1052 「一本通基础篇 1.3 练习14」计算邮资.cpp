#include <bits/stdc++.h>
using namespace std;

int w;
char c;

inline void input() {
    cin >> w >> c;
}

inline void solve() {
    int r = w > 1000 ? (w - 1000 + 499) / 500 * 4 + 8 : 8;
    if (c == 'y') {
        r += 5;
    }
    cout << r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
