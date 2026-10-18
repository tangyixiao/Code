#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, t, a[25], f[N];

inline void input() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    return;
}

inline void solve() {
    for (int i = 0; i <= t; i++) {
        f[i] = 0;
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = t; j >= a[i]; j--) {
            f[j] += f[j - a[i]];
        }
    }
    cout << f[t] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}