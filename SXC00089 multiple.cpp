#include <bits/stdc++.h>
using namespace std;
long long n, i, j, f[64][3][2], ans, b[64], len;
signed main() {
    if (fopen("multiple.in", "r")) {
        freopen("multiple.in", "r", stdin);
        freopen("multiple.out", "w", stdout);
    }
    scanf("%lld", &n);
    len = 0;
    for (long long t = n; t > 0; t >>= 1) {
        b[len++] = t & 1;
    }
    f[0][0][0] = 1;
    for (i = 0; i < len; i++) {
        int bit = b[len - 1 - i];
        for (j = 0; j < 3; j++) {
            for (int t = 0; t < 2; t++) {
                if (!f[i][j][t]) {
                    continue;
                }
                for (int d = 0; d <= (t ? 1 : bit); d++) {
                    int nt = t || (d < bit);
                    f[i + 1][(j + d) % 3][nt] += f[i][j][t];
                }
            }
        }
    }
    ans = f[len][0][0] + f[len][0][1] - 1;
    printf("%lld\n", ans);
    return 0;
}
