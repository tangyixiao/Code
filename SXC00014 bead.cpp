#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, i, j, k, x, y, cnt, up, dn;
int e[N][N];

signed main() {
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        e[x][y] = 1;
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (e[i][k] && e[k][j]) {
                    e[i][j] = 1;
                }
            }
        }
    }
    cnt = 0;
    for (i = 1; i <= n; i++) {
        up = 0;
        dn = 0;
        for (j = 1; j <= n; j++) {
            if (j != i) {
                if (e[j][i]) {
                    up++;
                }
                if (e[i][j]) {
                    dn++;
                }
            }
        }
        if (up > n / 2 || dn > n / 2) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
