#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int t, n;
long long a[N], b[N], s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (; t--;) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        int ok = 1, got = 0;
        long long c0 = 0, cc = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = a[i] + a[n + 1 - i];
        }
        for (int i = 1; i <= n && ok; i++) {
            int j = n + 1 - i;
            if (a[i] != a[j]) {
                long long dx = a[i] - a[j], dy = b[i] - b[j];
                if (dy % dx != 0) {
                    ok = 0;
                    break;
                }
                long long x = dy / dx;
                if (x < 0) {
                    ok = 0;
                    break;
                }
                long long r = b[i] - x * a[i];
                if (r % s[i] != 0) {
                    ok = 0;
                    break;
                }
                long long y = r / s[i];
                if (y < 0) {
                    ok = 0;
                    break;
                }
                if (got && (x != c0 || y != cc)) {
                    ok = 0;
                    break;
                }
                c0 = x, cc = y, got = 1;
            }
        }
        if (ok) {
            for (int i = 1; i <= n && ok; i++) {
                if (b[i] != c0 * a[i] + cc * s[i]) {
                    ok = 0;
                }
            }
        }
        if (ok) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
