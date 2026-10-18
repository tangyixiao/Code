#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int x[N], y[N], n, xa, ya, xb, yb, o[N];
long long d1[N], d2[N], s[N];

inline void input() {
    cin >> xa >> ya >> xb >> yb;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        d1[i] = 1LL * (x[i] - xa) * (x[i] - xa) + 1LL * (y[i] - ya) * (y[i] - ya);
        d2[i] = 1LL * (x[i] - xb) * (x[i] - xb) + 1LL * (y[i] - yb) * (y[i] - yb);
    }
    for (int i = 1; i <= n; i++) {
        o[i] = i;
    }
    return;
}

inline bool cmp(int i, int j) {
    return d1[i] < d1[j];
}

inline void solve() {
    sort(o + 1, o + n + 1, cmp);
    s[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        s[i] = max(s[i + 1], d2[o[i]]);
    }
    long long ans = s[1];
    for (int i = 1; i <= n; i++) {
        ans = min(ans, d1[o[i]] + s[i + 1]);
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
