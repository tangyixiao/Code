#include <bits/stdc++.h>
using namespace std;

int a[13];
int i;
int s, r;

inline void input() {
    for (i = 1; i <= 12; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    for (i = 1; i <= 12; ++i) {
        s += 300 - a[i];
        if (s < 0) {
            cout << -i << "\n";
            return;
        }
        r += s / 100 * 100, s %= 100;
    }
    cout << r * 6 / 5 + s << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
