#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, i, u, v, ec, head[N], nxt[2 * N], to[2 * N], w[2 * N], par[N], ord[N];
long long f1[N], f2[N], f3[N], ans;

void add(int a, int b, int c) {
    ec++;
    to[ec] = b;
    w[ec] = c;
    nxt[ec] = head[a];
    head[a] = ec;
}

signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n - 1; i++) {
        scanf("%d %d", &u, &v);
        add(u, i + 1, v);
        add(i + 1, u, v);
    }
    int qh = 1, qt = 1;
    ord[1] = 1;
    par[1] = 0;
    while (qh <= qt) {
        int x = ord[qh];
        qh++;
        for (int e = head[x]; e != 0; e = nxt[e]) {
            int y = to[e];
            if (y == par[x]) {
                continue;
            }
            par[y] = x;
            qt++;
            ord[qt] = y;
        }
    }
    for (i = 0; i <= n; i++) {
        f1[i] = 0;
        f2[i] = 0;
        f3[i] = 0;
    }
    ans = 0;
    for (i = n; i >= 1; i--) {
        int x = ord[i];
        long long b1 = 0, b2 = 0, b3 = 0, id1 = 0;
        for (int e = head[x]; e != 0; e = nxt[e]) {
            int y = to[e];
            if (par[y] != x) {
                continue;
            }
            long long c1 = w[e];
            long long c2 = (f1[y] > 0) ? w[e] + f1[y] : w[e];
            long long c3 = (f2[y] > 0) ? w[e] + f2[y] : 0;
            if (c1 > b1) {
                b1 = c1;
                id1 = y;
            }
            if (c2 > b2) {
                b2 = c2;
            }
            if (c3 > b3) {
                b3 = c3;
            }
        }
        f1[x] = b1;
        f2[x] = b2;
        f3[x] = b3;
    }
    for (i = 1; i <= n; i++) {
        int x = i;
        long long b2 = 0, bs = 0;
        for (int e = head[x]; e != 0; e = nxt[e]) {
            int y = to[e];
            if (par[y] != x) {
                continue;
            }
            long long c2 = (f1[y] > 0) ? w[e] + f1[y] : w[e];
            if (c2 > b2) {
                b2 = c2;
            }
        }
        for (int e = head[x]; e != 0; e = nxt[e]) {
            int y = to[e];
            if (par[y] != x) {
                continue;
            }
            long long c2 = (f1[y] > 0) ? w[e] + f1[y] : w[e];
            if (c2 == b2) {
                continue;
            }
            for (int e2 = head[x]; e2 != 0; e2 = nxt[e2]) {
                int z = to[e2];
                if (par[z] != x || z == y) {
                    continue;
                }
                long long v2 = c2 + w[e2];
                if (v2 > bs) {
                    bs = v2;
                }
            }
        }
        if (bs > ans) {
            ans = bs;
        }
        if (f3[x] > ans) {
            ans = f3[x];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
