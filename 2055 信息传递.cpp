#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, t[N], v[N], s[N], ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    ans = n;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        if (v[i]) {
            continue;
        }
        int u = i, c = 0;
        while (!v[u]) {
            v[u] = i, s[u] = ++c, u = t[u];
        }
        if (v[u] == i) {
            ans = min(ans, c - s[u] + 1);
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
