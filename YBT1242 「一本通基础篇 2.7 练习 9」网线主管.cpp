#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], n, k;

inline bool ck(int x) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
        c += a[i] / x;
    }
    return c >= k;
}

inline void input() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x, a[i] = x * 100 + 0.5;
    }
    return;
}

inline void solve() {
    if (!ck(1)) {
        printf("0.00\n");
        return;
    }
    int l = 1, r = 1e9, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (ck(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    printf("%d.%02d\n", l / 100, l % 100);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
