#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m, k, i, j, t, b, l, r, s, area, ans;
int a[N][N], c[N];
char line[N];
signed main() {
    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= n; i++) {
        scanf("%s", line + 1);
        for (j = 1; j <= m; j++) {
            a[i][j] = line[j] - '0';
        }
    }
    ans = 1e9;
    for (t = 1; t <= n; t++) {
        for (j = 1; j <= m; j++) {
            c[j] = 0;
        }
        for (b = t; b <= n; b++) {
            for (j = 1; j <= m; j++) {
                c[j] += a[b][j];
            }
            r = 0, s = 0;
            for (l = 1; l <= m; l++) {
                for (; r < m && s < k;) {
                    r++, s += c[r];
                }
                if (s >= k) {
                    area = (b - t + 1) * (r - l + 1);
                    if (area < ans) {
                        ans = area;
                    }
                }
                s -= c[l];
            }
        }
    }
    if (ans == 1e9) {
        ans = 0;
    }
    printf("%d\n", ans);
    return 0;
}
