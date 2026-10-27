#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, i, j, p, q, src, miss;
int v[N][N], cand[N];
bool ok;
signed main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++) {
                scanf("%d", &v[i][j]);
            }
        }
        int sum = 0;
        for (j = 0; j < n - 1; j++) {
            sum += v[0][j];
        }
        miss = n * (n + 1) / 2 - sum;
        for (p = 0; p < n; p++) {
            q = 0;
            src = 0;
            for (i = 0; i < n; i++) {
                if (i == p) {
                    cand[q++] = miss;
                } else {
                    cand[q++] = v[0][src++];
                }
            }
            ok = true;
            for (i = 0; i < n && ok; i++) {
                int idx = 0;
                for (j = 0; j < n && idx < n - 1; j++) {
                    if (cand[j] == v[i][idx]) {
                        idx++;
                    }
                }
                if (idx < n - 1) {
                    ok = false;
                }
            }
            if (ok) {
                for (i = 0; i < n; i++) {
                    if (i) {
                        printf(" ");
                    }
                    printf("%d", cand[i]);
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
