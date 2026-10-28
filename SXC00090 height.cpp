#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long m, a[N], r[N], d[N];

bool ok(long long x) {
    for (int i = 1; i <= n; i++) {
        r[i] = (x + a[i] - 1) / a[i];
    }
    if (n == 1) {
        return r[1] <= m;
    }
    d[n - 1] = r[n] - 1;
    if (d[n - 1] < 0) {
        d[n - 1] = 0;
    }
    for (int i = n - 2; i >= 1; i--) {
        long long v = r[i + 1] - d[i + 1] - 1;
        d[i] = v > 0 ? v : 0;
    }
    long long v = r[1] - 2;
    if (v > d[1]) {
        d[1] = v;
    }
    long long s = n;
    for (int i = 1; i <= n - 1; i++) {
        s += 2 * d[i];
        if (s > m) {
            return false;
        }
    }
    return s <= m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (; t; t--) {
        cin >> n >> m;
        long long mx = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > mx) {
                mx = a[i];
            }
        }
        long long lo = 0, hi = mx * m;
        for (; lo < hi;) {
            long long mid = (lo + hi + 1) / 2;
            if (ok(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << "\n";
    }
    return 0;
}
