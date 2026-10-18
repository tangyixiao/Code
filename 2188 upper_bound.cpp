#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, q, a[N];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    int l = 0, r = n;
    while (l < r) {
        int md = (l + r) / 2;
        if (a[md] > q) {
            r = md;
        } else {
            l = md + 1;
        }
    }
    cout << (l + 1 <= n ? l + 1 : n + 1) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    for (int i = 0; i < m; i++) {
        cin >> q;
        solve();
    }
    return 0;
}