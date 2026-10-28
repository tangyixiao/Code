#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int m, n, i, x, ok, lo, hi, mid;
long long a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a, a + m);
    for (i = 1; i <= n; i++) {
        cin >> x;
        lo = 0;
        hi = m - 1;
        ok = 0;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (a[mid] == x) {
                ok = 1;
                break;
            } else if (a[mid] < x) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (ok == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
