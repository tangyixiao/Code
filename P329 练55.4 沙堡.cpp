#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
int n, x, y, c[N], d[N];

inline void input() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
    }
}

inline void solve() {
    sort(c + 1, c + n + 1);
    sort(d + 1, d + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] < d[i]) {
            ans += 1LL * (d[i] - c[i]) * x;
        } else {
            ans += 1LL * (c[i] - d[i]) * y;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}