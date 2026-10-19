#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], m;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
}

inline void solve() {
    int x;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        int p = lower_bound(a + 1, a + n + 1, x) - a;
        if (p == 1) {
            cout << a[1] << "\n";
        } else if (p > n) {
            cout << a[n] << "\n";
        } else if (x - a[p - 1] <= a[p] - x) {
            cout << a[p - 1] << "\n";
        } else {
            cout << a[p] << "\n";
        }
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}