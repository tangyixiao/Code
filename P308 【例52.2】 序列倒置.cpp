#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int a[N], n;

inline void input() {
    for (n = 0; cin >> a[n]; n++) {
    }
}

inline void solve() {
    for (int i = n - 1; i >= 0; i--) {
        cout << a[i] << (i ? " " : "\n");
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
