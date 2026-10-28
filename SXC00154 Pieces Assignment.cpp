#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 9;
int n, m, k, i, j, t, a, b, w, h, nm, ca;
long long ans;
int ms[N];
long long cur[N][25], nxt[N][25];
signed main() {
    while (scanf("%d %d %d", &n, &m, &k) == 3) {
        w = min(n, m);
        h = max(n, m);
        nm = 0;
        for (i = 0; i < (1 << w); i++) {
            if ((i & (i << 1)) == 0) {
                ms[nm++] = i;
            }
        }
        for (i = 0; i < (1 << w); i++) {
            for (j = 0; j <= k; j++) {
                cur[i][j] = 0;
            }
        }
        cur[0][0] = 1;
        for (t = 0; t < h; t++) {
            for (i = 0; i < (1 << w); i++) {
                for (j = 0; j <= k; j++) {
                    nxt[i][j] = 0;
                }
            }
            for (a = 0; a < nm; a++) {
                ca = __builtin_popcount(ms[a]);
                for (b = 0; b < nm; b++) {
                    if (ms[a] & ms[b]) {
                        continue;
                    }
                    for (j = 0; j + ca <= k; j++) {
                        if (cur[ms[b]][j] == 0) {
                            continue;
                        }
                        nxt[ms[a]][j + ca] += cur[ms[b]][j];
                    }
                }
            }
            for (i = 0; i < (1 << w); i++) {
                for (j = 0; j <= k; j++) {
                    cur[i][j] = nxt[i][j];
                }
            }
        }
        ans = 0;
        for (a = 0; a < nm; a++) {
            ans += cur[ms[a]][k];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
