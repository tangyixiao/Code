#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int a[N], n, m, l;

inline void input() {
    cin >> l >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return;
}

inline bool ck(int x) {
    int p = 0, c = 0;
    for (int i = 0; i <= n; ++i) {
        if (i < n && a[i] - p < x) {
            ++c;
            continue;
        }
        if (i < n) {
            p = a[i];
        }
        if (i == n && l - p < x) {
            ++c;
        }
    }
    return c <= m;
}

inline void solve() {
    int lo = 0, hi = l, x;
    while (lo < hi) {
        x = (lo + hi + 1) / 2;
        if (ck(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    cout << lo << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
