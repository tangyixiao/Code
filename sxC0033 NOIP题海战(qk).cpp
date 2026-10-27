#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, k, i, j, q, id, typ;
int cnt[N], pro[N][N], vis[N];

signed main() {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &cnt[i]);
        for (j = 1; j <= cnt[i]; j++) {
            scanf("%d", &pro[i][j]);
        }
    }
    scanf("%d", &k);
    while (k > 0) {
        k--;
        scanf("%d %d", &typ, &q);
        for (j = 1; j <= m; j++) {
            vis[j] = 0;
        }
        for (i = 1; i <= q; i++) {
            scanf("%d", &id);
            for (j = 1; j <= cnt[id]; j++) {
                vis[pro[id][j]]++;
            }
        }
        int first = 1;
        for (j = 1; j <= m; j++) {
            int ok = 0;
            if (typ == 1) {
                if (vis[j] == q) {
                    ok = 1;
                }
            } else {
                if (vis[j] == 0) {
                    ok = 1;
                }
            }
            if (ok == 1) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", j);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
