#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int T, n, i, k, j, r;
long long C, f, cost, d[N], p[N], need;
long long mn[4 * N];
int idx[4 * N];
void build(int o, int l, int r) {
    if (l == r) {
        mn[o] = p[l], idx[o] = l;
        return;
    }
    int mid = (l + r) / 2;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    if (mn[o * 2] <= mn[o * 2 + 1]) {
        mn[o] = mn[o * 2], idx[o] = idx[o * 2];
    } else {
        mn[o] = mn[o * 2 + 1], idx[o] = idx[o * 2 + 1];
    }
}
int qfirst(int o, int l, int r, int ql, int qr, long long lim) {
    if (r < ql || qr < l || mn[o] >= lim) {
        return -1;
    }
    if (l == r) {
        return l;
    }
    int mid = (l + r) / 2;
    int res = qfirst(o * 2, l, mid, ql, qr, lim);
    if (res != -1) {
        return res;
    }
    return qfirst(o * 2 + 1, mid + 1, r, ql, qr, lim);
}
int qmin(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) {
        return -1;
    }
    if (ql <= l && r <= qr) {
        return idx[o];
    }
    int mid = (l + r) / 2, u = qmin(o * 2, l, mid, ql, qr), v = qmin(o * 2 + 1, mid + 1, r, ql, qr);
    if (u == -1) {
        return v;
    }
    if (v == -1) {
        return u;
    }
    return p[u] <= p[v] ? u : v;
}
signed main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld", &n, &C);
        d[0] = 0;
        for (i = 1; i <= n; i++) {
            scanf("%lld", &d[i]);
        }
        for (i = 0; i < n; i++) {
            scanf("%lld", &p[i]);
        }
        p[n] = -1;
        build(1, 1, n);
        i = 0, f = 0, cost = 0;
        for (; i < n;) {
            r = i;
            for (k = i + 1; k <= n && d[k] - d[i] <= C; k++) {
                r = k;
            }
            if (r == i) {
                break;
            }
            j = qfirst(1, 1, n, i + 1, r, p[i]);
            if (j != -1) {
                need = d[j] - d[i];
                if (f < need) {
                    cost += (need - f) * p[i], f = need;
                }
                f -= need, i = j;
            } else {
                j = qmin(1, 1, n, i + 1, r);
                cost += (C - f) * p[i], f = C;
                f -= d[j] - d[i], i = j;
            }
        }
        printf("%lld\n", cost);
    }
    return 0;
}
