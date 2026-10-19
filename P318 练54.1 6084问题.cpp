#include <bits/stdc++.h>
using namespace std;

const int N = 5 + 5;

int n, d[4];

inline void input() {
    cin >> n;
    for (int i = 0; i < 4; i++) {
        d[i] = n % 10, n /= 10;
    }
}

inline void solve() {
    sort(d, d + 4);
    int mx = 0, mn = 0;
    for (int i = 3; i >= 0; i--) {
        mx = mx * 10 + d[i], mn = mn * 10 + d[3 - i];
    }
    cout << mx - mn << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
