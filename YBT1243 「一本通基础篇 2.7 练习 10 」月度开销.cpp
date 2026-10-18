#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], n, m;

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return;
}

inline bool ck(int x) {
    int s = 0, c = 1;
    for (int i = 0; i < n; ++i) {
        if (s + a[i] > x) {
            ++c, s = 0;
        }
        s += a[i];
    }
    return c <= m;
}

inline void solve() {
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        l = max(l, a[i]), r += a[i];
    }
    while (l < r) {
        int q = (l + r) / 2;
        if (ck(q)) {
            r = q;
        } else {
            l = q + 1;
        }
    }
    cout << l << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
