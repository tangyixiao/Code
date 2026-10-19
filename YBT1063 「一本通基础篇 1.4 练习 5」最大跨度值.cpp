#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    int mx = a[1], mn = a[1];
    for (int i = 2; i <= n; ++i) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    cout << mx - mn << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}