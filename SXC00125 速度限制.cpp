#include <bits/stdc++.h>
using namespace std;
const int N = 155;
const int S = 505;
const double INF = 1e18;
int n, m, dst, i, a, b, v, l, e, u, sp, ns, nu, k, best, ec;
int head[N], nxt[22505], to[22505], lim[22505], len[22505];
int pu[N][S], ps[N][S], path[N * S], pc;
double d[N][S], nd, bt;
struct node {
    double w;
    int u, v;
    bool operator<(const node &o) const {
        return w > o.w;
    }
};
priority_queue<node> q;
signed main() {
    scanf("%d%d%d", &n, &m, &dst);
    for (i = 1; i <= n; i++) {
        head[i] = -1;
    }
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &a, &b, &v, &l);
        a++, b++;
        to[i] = b, lim[i] = v, len[i] = l, nxt[i] = head[a], head[a] = i;
    }
    for (i = 1; i <= n; i++) {
        for (int j = 0; j <= 500; j++) {
            d[i][j] = INF;
        }
    }
    d[1][70] = 0;
    q.push((node){0, 1, 70});
    for (; !q.empty();) {
        node t = q.top();
        q.pop();
        u = t.u, sp = t.v;
        if (t.w > d[u][sp] + 1e-12) {
            continue;
        }
        for (e = head[u]; e != -1; e = nxt[e]) {
            nu = to[e];
            if (lim[e] > 0) {
                ns = lim[e];
                nd = t.w + (double)len[e] / ns;
            } else {
                if (sp == 0) {
                    continue;
                }
                ns = sp;
                nd = t.w + (double)len[e] / sp;
            }
            if (nd < d[nu][ns] - 1e-12) {
                d[nu][ns] = nd;
                pu[nu][ns] = u, ps[nu][ns] = sp;
                q.push((node){nd, nu, ns});
            }
        }
    }
    dst++;
    best = -1, bt = INF;
    for (k = 0; k <= 500; k++) {
        if (d[dst][k] < bt - 1e-12) {
            bt = d[dst][k], best = k;
        }
    }
    u = dst, sp = best, pc = 0;
    for (; u != 1;) {
        path[pc++] = u - 1;
        nu = pu[u][sp], sp = ps[u][sp], u = nu;
    }
    printf("0");
    for (i = pc - 1; i >= 0; i--) {
        printf(" %d", path[i]);
    }
    printf("\n");
    return 0;
}
