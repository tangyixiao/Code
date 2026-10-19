#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a[N], f[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 0; i <= 3; i++) {
        f[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        f[i + 2] = max(f[i + 1], f[i - 1] + a[i - 1] + a[i]);
    }
    cout << f[n + 2] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
