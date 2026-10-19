#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a[N], mn, mx;

inline void input() {
    cin >> n;
    mn = 1e9, mx = -1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
    }
}

inline void solve() {
    cout << mn << " " << mx << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
