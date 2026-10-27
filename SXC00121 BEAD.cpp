#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m, x, y, i, j, k, ans, r[N][N], gt[N], lt[N];
signed main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        r[i][i] = 1;
    }
    for (i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        r[x][y] = 1;
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
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i != j && r[i][j]) {
                gt[i]++, lt[j]++;
            }
        }
        if (gt[i] > n / 2 || lt[i] > n / 2) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
