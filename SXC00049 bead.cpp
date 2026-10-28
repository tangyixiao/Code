#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, h[N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j, k, x, y;
    while (cin >> n) {
        cin >> m;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                h[i][j] = 0;
            }
        }
        for (i = 1; i <= m; i++) {
            cin >> x >> y;
            h[x][y] = 1;
        }
        for (k = 1; k <= n; k++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (h[i][k] && h[k][j]) {
                        h[i][j] = 1;
                    }
                }
            }
        }
        int ans = 0, lim = (n + 1) / 2;
        for (i = 1; i <= n; i++) {
            int up = 0, dn = 0;
            for (j = 1; j <= n; j++) {
                if (h[j][i]) {
                    up++;
                }
                if (h[i][j]) {
                    dn++;
                }
            }
            if (up >= lim || dn >= lim) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
