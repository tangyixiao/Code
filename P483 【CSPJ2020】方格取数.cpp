#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, a[N][N];
long long f[N], g[N], s[N], b;
int i, j, t;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (i = 1, t = 0; i <= n; i++) {
        f[i] = (t += a[i][1]);
    }
    for (j = 2; j <= m; j++) {
        for (i = 1, t = 0; i <= n; i++) {
            s[i] = (t += a[i][j]);
        }
        for (i = 1, b = -1e18; i <= n; i++) {
            b = max(b, f[i] - s[i - 1]);
            g[i] = b + s[i];
        }
        for (i = n, b = -1e18; i >= 1; i--) {
            b = max(b, f[i] + s[i]);
            f[i] = max(g[i], b - s[i - 1]);
        }
    }
    cout << f[n] << "\n";
    return 0;
}
