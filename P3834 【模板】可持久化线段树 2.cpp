#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 200005;
const int MAXM = MAXN * 20;

int n, m, a[MAXN], b[MAXN], sz;
int root[MAXN], tot;
int sum[MAXM], lson[MAXM], rson[MAXM];

int build(int l, int r) {
    int rt = ++tot;
    sum[rt] = 0;
    if (l < r) {
        int mid = (l + r) >> 1;
        lson[rt] = build(l, mid);
        rson[rt] = build(mid + 1, r);
    }
    return rt;
}

int update(int pre, int l, int r, int pos) {
    int rt = ++tot;
    lson[rt] = lson[pre];
    rson[rt] = rson[pre];
    sum[rt] = sum[pre] + 1;
    if (l < r) {
        int mid = (l + r) >> 1;
        if (pos <= mid)
            lson[rt] = update(lson[pre], l, mid, pos);
        else
            rson[rt] = update(rson[pre], mid + 1, r, pos);
    }
    return rt;
}

int query(int u, int v, int l, int r, int k) {
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int x = sum[lson[v]] - sum[lson[u]];
    if (k <= x)
        return query(lson[u], lson[v], l, mid, k);
    else
        return query(rson[u], rson[v], mid + 1, r, k - x);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    sz = unique(b + 1, b + n + 1) - (b + 1);

    root[0] = build(1, sz);
    for (int i = 1; i <= n; ++i) {
        int pos = lower_bound(b + 1, b + sz + 1, a[i]) - b;
        root[i] = update(root[i - 1], 1, sz, pos);
    }

    while (m--) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int idx = query(root[l - 1], root[r], 1, sz, k);
        printf("%d\n", b[idx]);
    }

    return 0;
}