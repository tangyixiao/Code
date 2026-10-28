#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000, N = 1010, K = 55;
int c[N][K];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= 50 && j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
    int t;
    cin >> t;
    for (; t--;) {
        int n, w, h, d;
        long long ans = 0;
        cin >> n >> w >> h >> d;
        if (n == 1) {
            cout << (long long)(w + 1) * (h + 1) % MOD << "\n";
            continue;
        }
        for (int dx = 0; dx <= w; dx++) {
            for (int dy = -h; dy <= h; dy++) {
                if (dx == 0 && dy <= 0) {
                    continue;
                }
                if (dy == 0 && dx == 0) {
                    continue;
                }
                int ax = dx, ay = abs(dy);
                if (__gcd(ax, ay) != 1) {
                    continue;
                }
                long long l2 = (long long)ax * ax + (long long)ay * ay;
                int m = 1;
                for (; (long long)m * m * l2 < (long long)d * d; m++) {
                }
                int jmax = 0;
                if (ax > 0) {
                    jmax = w / ax + 1;
                }
                if (ay > 0) {
                    int v = h / ay + 1;
                    jmax = (jmax == 0 || v < jmax) ? v : jmax;
                }
                long long need = (long long)(n - 1) * (m - 1);
                for (int j = n; j <= jmax; j++) {
                    long long a0 = 0, a1 = 0, a2 = 0;
                    long long u = (long long)w - (long long)(j - 1) * ax + 1;
                    long long v2 = (long long)h - (long long)(j - 1) * ay + 1;
                    if (u > 0 && v2 > 0) {
                        a0 = u * v2;
                    }
                    u = (long long)w - (long long)j * ax + 1;
                    v2 = (long long)h - (long long)j * ay + 1;
                    if (u > 0 && v2 > 0) {
                        a1 = u * v2;
                    }
                    u = (long long)w - (long long)(j + 1) * ax + 1;
                    v2 = (long long)h - (long long)(j + 1) * ay + 1;
                    if (u > 0 && v2 > 0) {
                        a2 = u * v2;
                    }
                    long long cnt = a0 - 2 * a1 + a2;
                    if (cnt <= 0) {
                        continue;
                    }
                    long long idx = (long long)j - need;
                    if (idx < n) {
                        continue;
                    }
                    ans = (ans + cnt % MOD * c[idx][n]) % MOD;
                }
            }
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}
