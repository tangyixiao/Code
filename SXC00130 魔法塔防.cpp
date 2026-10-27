#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
long long n, r, g, b, t;
long long f[N][N];

signed main() {
    cin >> n >> r >> g >> b >> t;
    long long p, q;
    for (p = 0; p <= n; p++) {
        for (q = 0; q <= n; q++) {
            f[p][q] = -1;
        }
    }
    f[0][0] = 0;
    for (p = 0; p <= n; p++) {
        for (q = 0; q <= n - p; q++) {
            if (f[p][q] < 0) {
                continue;
            }
            long long cur = f[p][q], v;
            v = cur + (t + b * p) * (g * q);
            if (p + 1 <= n) {
                if (v > f[p + 1][q]) {
                    f[p + 1][q] = v;
                }
            }
            if (q + 1 <= n) {
                if (v > f[p][q + 1]) {
                    f[p][q + 1] = v;
                }
            }
        }
    }
    long long ans = 0;
    for (p = 0; p <= n; p++) {
        for (q = 0; q <= n - p; q++) {
            if (f[p][q] < 0) {
                continue;
            }
            long long v = f[p][q] + (n - p - q) * (t + b * p) * (r + g * q);
            if (v > ans) {
                ans = v;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
