#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;

int n, m;
int f[MAXN], w[MAXN];
int pre[MAXN], pre2[MAXN], last[MAXN];

struct SegTree {
    ll mx[MAXN * 4], tag[MAXN * 4];
    void push_up(int rt) {
        mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
    }
    void push_down(int rt) {
        if (tag[rt]) {
            tag[rt << 1] += tag[rt];
            tag[rt << 1 | 1] += tag[rt];
            mx[rt << 1] += tag[rt];
            mx[rt << 1 | 1] += tag[rt];
            tag[rt] = 0;
        }
    }
    void update(int rt, int l, int r, int ql, int qr, ll val) {
        if (ql > qr)
            return;
        if (ql <= l && r <= qr) {
            mx[rt] += val;
            tag[rt] += val;
            return;
        }
        push_down(rt);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            update(rt << 1, l, mid, ql, qr, val);
        if (qr > mid)
            update(rt << 1 | 1, mid + 1, r, ql, qr, val);
        push_up(rt);
    }
    ll query_max() {
        return mx[1];
    }
} seg;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &f[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &w[i]);

    for (int i = 1; i <= n; ++i) {
        int c = f[i];
        pre[i] = last[c];
        pre2[i] = pre[pre[i]];
        last[c] = i;
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int c = f[i];
        int p = pre[i], q = pre2[i];
        if (p > 0) {
            seg.update(1, 1, n, q + 1, p, -w[c]);
        }
        seg.update(1, 1, n, p + 1, i, w[c]);
        ans = max(ans, seg.query_max());
    }
    printf("%lld\n", ans);
    return 0;
}