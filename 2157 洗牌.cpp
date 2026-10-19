#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, k, p, a[N], b[N], c[N];

inline void input() {
    cin >> n >> k;
    p = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for (int t = 1; t <= k; t++) {
        int m = 0;
        for (int i = 1; i <= n / 2; i++) {
            b[++m] = a[i], c[m] = a[i + n / 2];
        }
        for (int i = 1; i <= m; i++) {
            a[2 * i - 1] = b[i], a[2 * i] = c[i];
        }
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i < n ? " " : "\n");
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