#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N], b[N], mv[N], t, cur[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> mv[i];
    }
    cin >> t;
}

inline void solve() {
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        int m = t;
        for (int i = 1; i < k; i++) {
            m -= mv[i];
        }
        if (m <= 0) {
            break;
        }
        for (int i = 1; i <= k; i++) {
            cur[i] = a[i];
        }
        int s = 0;
        for (int i = 1; i <= m; i++) {
            int p = 0;
            for (int j = 1; j <= k; j++) {
                if (cur[j] > cur[p]) {
                    p = j;
                }
            }
            if (cur[p] <= 0) {
                break;
            }
            s += cur[p];
            cur[p] -= b[p];
        }
        ans = max(ans, s);
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
