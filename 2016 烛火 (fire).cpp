#include <bits/stdc++.h>
using namespace std;

int n, k;
double s = 0;

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t, s += t;
    }
}

inline void solve() {
    cout << fixed << setprecision(3) << s / k << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
