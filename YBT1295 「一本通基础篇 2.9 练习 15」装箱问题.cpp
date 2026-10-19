#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int v, n, a[N], f[N];

inline void input() {
    cin >> v >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    return;
}

inline void solve() {
    for (int i = 0; i <= v; i++) {
        f[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
    }
    cout << v - f[v] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}