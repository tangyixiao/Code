#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
int n, m, i, x, y, z, head[N], nxt[M], to[M], wt[M], ec;
int ord[M], ov[M], cnt[N], b[N];
bool cmp(int u, int v) {
    return to[u] < to[v] || (to[u] == to[v] && u < v);
}
signed main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        head[i] = -1;
    }
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        to[i] = y, wt[i] = z, nxt[i] = head[x], head[x] = i;
    }
    for (i = 1; i <= n; i++) {
        int c = 0;
        for (int e = head[i]; e != -1; e = nxt[e]) {
            ord[c++] = e;
        }
        sort(ord, ord + c, cmp);
        printf("%d:\n", i);
        for (int t = 0; t < c; t++) {
            printf("%d %d\n", to[ord[t]], wt[ord[t]]);
        }
    }
    return 0;
}
