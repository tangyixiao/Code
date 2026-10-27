#include <bits/stdc++.h>
using namespace std;

const int N = 16, M = 1 << 15;
int n;
double x[N], y[N], d[N][N], f[M][N];

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        d[i][n] = sqrt(x[i] * x[i] + y[i] * y[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double dx = x[i] - x[j], dy = y[i] - y[j];
            d[i][j] = sqrt(dx * dx + dy * dy);
        }
    }
    int lim = 1 << n;
    for (int s = 0; s < lim; s++) {
        for (int i = 0; i < n; i++) {
            f[s][i] = 1e18;
        }
    }
    for (int i = 0; i < n; i++) {
        f[1 << i][i] = d[i][n];
    }
    for (int s = 1; s < lim; s++) {
        for (int i = 0; i < n; i++) {
            if (!(s >> i & 1) || f[s][i] > 5e17) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (s >> j & 1) {
                    continue;
                }
                double v = f[s][i] + d[i][j];
                if (v < f[s | (1 << j)][j]) {
                    f[s | (1 << j)][j] = v;
                }
            }
        }
    }
    double ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, f[lim - 1][i]);
    }
    cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}
