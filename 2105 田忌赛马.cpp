#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int n, u[N], v[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> u[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    sort(u + 1, u + n + 1), sort(v + 1, v + n + 1);
}

inline void solve() {
    int i = 1, j = 1, ans = 0;
    for (; i <= n && j <= n;) {
        if (u[i] > v[j]) {
            ++ans, ++i, ++j;
        } else {
            ++i;
        }
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
