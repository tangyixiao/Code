#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
double a[N], s, mn, mx, av, d;

inline void input() {
    cin >> n;
    mn = 1e18, mx = -1e18;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], s += a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
    }
}

inline void solve() {
    if (n < 3) {
        cout << "0.00 0.00\n";
        return;
    }
    av = (s - mn - mx) / (n - 2);
    for (int i = 1; i <= n; i++) {
        if (a[i] != mn && a[i] != mx) {
            d = max(d, fabs(a[i] - av));
        }
    }
    cout << fixed << setprecision(2) << av << " " << d << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
