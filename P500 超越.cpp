#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, i, p;
long long a[N], x;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= q; i++) {
        cin >> x;
        p = lower_bound(a + 1, a + n + 1, x) - a;
        if (p > n) {
            cout << -1 << "\n";
        } else {
            for (; p + 1 <= n && a[p + 1] == a[p];) {
                p++;
            }
            cout << p << "\n";
        }
    }
    return 0;
}
