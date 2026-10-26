#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, p[N][N], t[N][N], r[N][N];
double d[N];

signed main() {
    int i, j, k;
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> p[i][j];
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> t[i][j];
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j || p[i][j] > 0) {
                r[i][j] = 1;
            }
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (r[i][k] && r[k][j]) {
                    r[i][j] = 1;
                }
            }
        }
    }
    double lo = 0, hi = 1e6;
    for (int it = 0; it < 80; it++) {
        double mid = (lo + hi) / 2;
        for (i = 1; i <= n; i++) {
            d[i] = -1e18;
        }
        d[1] = 0;
        int pos = 0;
        for (k = 1; k <= n; k++) {
            int upd = 0;
            for (i = 1; i <= n; i++) {
                if (d[i] < -1e17) {
                    continue;
                }
                for (j = 1; j <= n; j++) {
                    if (i == j || p[i][j] <= 0 || !r[j][n]) {
                        continue;
                    }
                    double w = p[i][j] - mid * t[i][j];
                    if (d[i] + w > d[j]) {
                        d[j] = d[i] + w, upd = 1;
                    }
                }
            }
            if (!upd) {
                break;
            }
            if (k == n) {
                pos = 1;
            }
        }
        if (pos || d[n] > -1e-9) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(3) << (lo + hi) / 2 << "\n";
    return 0;
}
