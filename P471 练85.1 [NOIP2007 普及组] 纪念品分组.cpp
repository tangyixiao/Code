#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;

int w, n, a[N], l, r;

inline void input() {
    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}

inline void solve() {
    l = 1, r = n;
    int ans = 0;
    for (; l <= r; ans++) {
        if (a[l] + a[r] <= w) {
            l++;
        }
        if (l <= r) {
            r--;
        }
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
