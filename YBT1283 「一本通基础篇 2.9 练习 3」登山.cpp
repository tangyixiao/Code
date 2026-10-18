#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N], f[N], g[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        f[i] = i > 1 && a[i] > a[i - 1] ? f[i - 1] + 1 : 1;
    }
    for (int i = n; i >= 1; i--) {
        g[i] = i < n && a[i] > a[i + 1] ? g[i + 1] + 1 : 1;
    }
    int r = 0;
    for (int i = 1; i <= n; i++) {
        r = max(r, f[i] + g[i] - 1);
    }
    cout << r << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}