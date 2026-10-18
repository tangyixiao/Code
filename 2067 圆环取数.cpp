#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
long long a[N], mx, mn, cur, low, tot;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], tot += a[i];
    }
}

inline void solve() {
    cur = mx = a[1];
    for (int i = 2; i <= n; i++) {
        cur = max(a[i], cur + a[i]);
        mx = max(mx, cur);
    }
    low = mn = a[n];
    for (int i = n - 1; i >= 1; i--) {
        low = min(a[i], low + a[i]);
        mn = min(mn, low);
    }
    cout << max(mx, tot - mn) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
