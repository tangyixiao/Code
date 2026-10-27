#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 5e5 + 5;
int n, m, q, ec, tot, i, u, v, w, k;
long long sum;
int fa[N], head[N], nxt[M * 2], to[M * 2], eid[M * 2], dep[N], par[N], parid[N];
int nxtu[N], istree[M], ic[M], qu[N];
struct E {
    int u, v, w, id;
} e[M];
bool cmp(const E &p, const E &q2) {
    if (p.w != q2.w) {
        return p.w < q2.w;
    }
    return p.id < q2.id;
}
int find(int x) {
    while (fa[x] != x) {
        fa[x] = fa[fa[x]];
        x = fa[x];
    }
    return x;
}
int findu(int x) {
    while (nxtu[x] != x) {
        nxtu[x] = nxtu[nxtu[x]];
        x = nxtu[x];
    }
    return x;
}
void add(int a, int b, int c) {
    ec++;
    to[ec] = b;
    eid[ec] = c;
    nxt[ec] = head[a];
    head[a] = ec;
}
void paint(int a, int b, int w2) {
    while (1) {
        int ra = findu(a), rb = findu(b);
        if (ra == rb) {
            return;
        }
        if (dep[ra] < dep[rb]) {
            int t = ra;
            ra = rb;
            rb = t;
        }
        ic[parid[ra]] = w2;
        nxtu[ra] = findu(par[ra]);
    }
}
char buf[1 << 26];
int pp, lp;
int rd() {
    int r = 0;
    while (pp < lp && (buf[pp] < '0' || buf[pp] > '9')) {
        pp++;
    }
    while (pp < lp && buf[pp] >= '0' && buf[pp] <= '9') {
        r = r * 10 + buf[pp] - '0';
        pp++;
    }
    return r;
}
signed main() {
    lp = fread(buf, 1, sizeof(buf), stdin);
    n = rd();
    m = rd();
    for (i = 1; i <= m; i++) {
        e[i].u = rd();
        e[i].v = rd();
        e[i].w = rd();
        e[i].id = i;
    }
    for (i = 1; i <= n; i++) {
        fa[i] = i;
        head[i] = 0;
    }
    sort(e + 1, e + m + 1, cmp);
    tot = 0;
    sum = 0;
    for (i = 1; i <= m; i++) {
        int ru = find(e[i].u), rv = find(e[i].v);
        if (ru != rv) {
            fa[ru] = rv;
            tot++;
            sum += e[i].w;
            istree[e[i].id] = 1;
            add(e[i].u, e[i].v, e[i].id);
            add(e[i].v, e[i].u, e[i].id);
        }
    }
    int conn = (tot == n - 1);
    for (i = 1; i <= n; i++) {
        dep[i] = -1;
        nxtu[i] = i;
    }
    int qh = 0, qt = 0;
    dep[1] = 0;
    par[1] = 0;
    nxtu[0] = 0;
    qu[qt++] = 1;
    while (qh < qt) {
        int x = qu[qh++];
        for (int t = head[x]; t; t = nxt[t]) {
            int y = to[t];
            if (dep[y] != -1) {
                continue;
            }
            dep[y] = dep[x] + 1;
            par[y] = x;
            parid[y] = eid[t];
            qu[qt++] = y;
        }
    }
    for (i = 1; i <= m; i++) {
        ic[i] = 1e9;
    }
    for (i = 1; i <= m; i++) {
        if (istree[e[i].id] == 1) {
            continue;
        }
        paint(e[i].u, e[i].v, e[i].w);
    }
    q = rd();
    for (i = 1; i <= q; i++) {
        k = rd();
        if (conn == 0) {
            printf("Not connected\n");
            continue;
        }
        if (istree[k] == 0) {
            printf("%lld\n", sum);
            continue;
        }
        if (ic[k] >= 1e9) {
            printf("Not connected\n");
            continue;
        }
        printf("%lld\n", sum - e[k].w + ic[k]);
    }
    return 0;
}
