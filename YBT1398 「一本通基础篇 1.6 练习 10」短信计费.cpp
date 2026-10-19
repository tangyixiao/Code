#include <bits/stdc++.h>
using namespace std;

int n, a;

inline void input() { cin >> n; }

inline void solve() {
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        ans += (a + 69) / 70 * 0.1;
    }
    cout << fixed << setprecision(1) << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}