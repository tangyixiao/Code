#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a[N], f[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    f[1] = a[1], f[2] = a[1] + a[2];
    for (int i = 3; i <= n; i++) {
        f[i] = max(max(f[i - 1], f[i - 2] + a[i]), f[i - 3] + a[i - 1] + a[i]);
    }
    cout << f[n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
