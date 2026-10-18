#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, V = 1e3 + 5;
int m, n, a[N], c[V], b[N];

inline void input() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    int t = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (c[a[i]]) {
            continue;
        }
        ans++;
        if (t == m) {
            c[b[1]] = 0;
            for (int j = 1; j < m; j++) {
                b[j] = b[j + 1];
            }
        } else {
            t++;
        }
        b[t] = a[i], c[a[i]] = 1;
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}