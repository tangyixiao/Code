#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int r[N][N], n, m, i, j, k, ans = 0;
signed main() {
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        r[x][y] = 1;
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            if (r[i][k] == 0) {
                continue;
            }
            for (j = 1; j <= n; j++) {
                if (r[k][j] == 1) {
                    r[i][j] = 1;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (r[i][j] == 0 && r[j][i] == 0) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
