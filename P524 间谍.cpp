#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
const int M = 3e5 + 5;
int head[N], nxt[M], to[M], ec;
int mi[N], hi[N], kh[N], vis[N], q[N];
int n, i, j, k, x, hc;
void add(int u, int v) {
    ec++;
    to[ec] = v, nxt[ec] = head[u], head[u] = ec;
}
signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &mi[i]);
        if (mi[i] == 0) {
            hi[++hc] = i;
        }
        for (j = 1; j <= mi[i]; j++) {
            scanf("%d", &x);
            add(x, i);
        }
    }
    for (k = 1; k <= hc; k++) {
        int hd = 0, tl = 0, e, u;
        for (i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        vis[hi[k]] = 1, q[tl++] = hi[k];
        while (hd < tl) {
            u = q[hd++];
            for (e = head[u]; e; e = nxt[e]) {
                if (vis[to[e]] == 0) {
                    vis[to[e]] = 1, q[tl++] = to[e];
                }
            }
        }
        for (i = 1; i <= n; i++) {
            if (vis[i] == 1) {
                kh[i]++;
            }
        }
    }
    int f = 0;
    for (i = 1; i <= n; i++) {
        if (mi[i] > 0 && kh[i] <= 1) {
            printf("%d\n", i);
            f = 1;
        }
    }
    if (f == 0) {
        printf("BRAK\n");
    }
    return 0;
}
