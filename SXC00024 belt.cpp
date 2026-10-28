#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, A, B, C, D, i, j, ans;
int a[N][N], s[N][N], w[N][N], v1[N][N], v2[N][N];
int q[N], qh, qt;
signed main() {
    scanf("%d %d %d %d %d %d", &n, &m, &A, &B, &C, &D);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int rn = n - C + 1, cn = m - D + 1;
    for (i = 1; i <= rn; i++) {
        for (j = 1; j <= cn; j++) {
            w[i][j] = s[i + C - 1][j + D - 1] - s[i - 1][j + D - 1] - s[i + C - 1][j - 1] + s[i - 1][j - 1];
        }
    }
    for (j = 1; j <= cn; j++) {
        qh = 0;
        qt = 0;
        for (i = 1; i <= rn; i++) {
            while (qh < qt && w[q[qt - 1]][j] >= w[i][j]) {
                qt--;
            }
            q[qt++] = i;
            while (q[qh] <= i - A + C) {
                qh++;
            }
            if (i >= A - C) {
                v1[i][j] = w[q[qh]][j];
            }
        }
    }
    for (i = A - C; i <= rn; i++) {
        qh = 0;
        qt = 0;
        for (j = 1; j <= cn; j++) {
            while (qh < qt && v1[i][q[qt - 1]] >= v1[i][j]) {
                qt--;
            }
            q[qt++] = j;
            while (q[qh] <= j - B + D) {
                qh++;
            }
            if (j >= B - D) {
                v2[i][j] = v1[i][q[qh]];
            }
        }
    }
    ans = -1e9;
    for (i = A; i <= n; i++) {
        for (j = B; j <= m; j++) {
            int bs = s[i][j] - s[i - A][j] - s[i][j - B] + s[i - A][j - B];
            int mn = v2[i - C][j - D];
            if (bs - mn > ans) {
                ans = bs - mn;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
