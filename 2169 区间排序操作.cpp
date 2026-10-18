#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], n, mn[N], ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    mn[n + 1] = 2e9 + 7;
    for (int i = n; i >= 1; --i) {
        mn[i] = min(a[i], mn[i + 1]);
    }
    int mx = -2e9 - 7, st = 1;
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, a[i]);
        if (i < n && mx <= mn[i + 1]) {
            if (i - st + 1 >= 2) {
                ans += i - st + 1;
            }
            st = i + 1;
        }
    }
    if (n - st + 1 >= 2) {
        ans += n - st + 1;
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}