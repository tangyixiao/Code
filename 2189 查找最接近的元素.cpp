#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
}

inline void solve() {
    for (; m; --m, --n) {
        int x;
        cin >> x;
        int k = lower_bound(a + 1, a + n + 1, x) - a;
        int r;
        if (k > n) {
            r = n;
        } else if (k == 1 || x - a[k - 1] <= a[k] - x) {
            r = k - 1;
        } else {
            r = k;
        }
        cout << a[r] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}