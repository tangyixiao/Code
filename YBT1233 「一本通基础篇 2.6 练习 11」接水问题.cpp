#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int a[N], t[N], n, m;

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return;
}

inline void solve() {
    int k = m < n ? m : n;
    for (int i = 0; i < k; ++i) {
        t[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        int j = 0;
        for (int q = 1; q < k; ++q) {
            if (t[q] < t[j]) {
                j = q;
            }
        }
        t[j] += a[i];
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans = max(ans, t[i]);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
