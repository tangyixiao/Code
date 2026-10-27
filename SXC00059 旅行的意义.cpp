#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 4e5 + 5;
int hd[N], nx[M], to[M], ei[M], ec;
int gone[N], dg[N], alive[N], qq[N], ans[N];
int ae[N], be[N], n, m, k, i, x, y, h, t, cur;
void add(int u, int v, int e) {
    ec++;
    to[ec] = v, ei[ec] = e, nx[ec] = hd[u], hd[u] = ec;
}
void peel(int st) {
    h = 0, t = 0;
    qq[t++] = st;
    for (; h < t;) {
        int u = qq[h++];
        if (!alive[u]) {
            continue;
        }
        alive[u] = 0;
        cur--;
        for (int p = hd[u]; p; p = nx[p]) {
            int e = ei[p];
            if (gone[e]) {
                continue;
            }
            gone[e] = 1;
            int v = to[p];
            if (alive[v]) {
                dg[v]--;
                if (dg[v] < k) {
                    qq[t++] = v;
                }
            }
        }
    }
}
signed main() {
    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        ae[i] = x, be[i] = y;
        add(x, y, i), add(y, x, i);
        dg[x]++, dg[y]++;
    }
    for (i = 1; i <= n; i++) {
        alive[i] = 1;
    }
    cur = n;
    for (i = 1; i <= n; i++) {
        if (alive[i] && dg[i] < k) {
            peel(i);
        }
    }
    ans[m] = cur;
    for (i = m; i >= 2; i--) {
        x = ae[i], y = be[i];
        if (!gone[i]) {
            gone[i] = 1;
            dg[x]--, dg[y]--;
            if (alive[x] && dg[x] < k) {
                peel(x);
            }
            if (alive[y] && dg[y] < k) {
                peel(y);
            }
        }
        ans[i - 1] = cur;
    }
    for (i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
