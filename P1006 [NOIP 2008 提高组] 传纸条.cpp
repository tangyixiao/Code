#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
int m, n, a[maxn][maxn], F[2 * maxn][maxn][maxn];
signed main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(F, -1, sizeof(F));
    F[2][1][1] = 0;
    for (int k = 3; k < m + n; k++) {
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int s = F[k][i][j];
                if (F[k - 1][i][j] > s) {
                    s = F[k - 1][i][j];
                }
                if (F[k - 1][i - 1][j] > s) {
                    s = F[k - 1][i - 1][j];
                }
                if (F[k - 1][i][j - 1] > s) {
                    s = F[k - 1][i][j - 1];
                }
                if (F[k - 1][i - 1][j - 1] > s) {
                    s = F[k - 1][i - 1][j - 1];
                }
                if (s == -1) {
                    continue;
                }
                F[k][i][j] = s + a[k - i][i] + a[k - j][j];
            }
        }
    }
    printf("%d", F[m + n - 1][n - 1][n]);
    return 0;
}