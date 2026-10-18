#include <bits/stdc++.h>
using namespace std;

int a, b, c, s;

inline void input() {
    cin >> a >> b >> c;
    return;
}

inline void solve() {
    for (int x = 0; x * a <= c; x++) {
        if ((c - x * a) % b == 0) {
            s++;
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