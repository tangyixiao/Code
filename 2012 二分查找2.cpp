#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;

int a[N], n, t;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> t;
}

inline void solve() {
    while (t--) {
        int k;
        cin >> k;
        int p = upper_bound(a + 1, a + n + 1, k) - a;
        cout << (p > 1 && a[p - 1] == k ? p - 1 : -1) << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}