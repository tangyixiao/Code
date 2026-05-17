#include <algorithm>
#include <cstdio>

#define ls p << 1
#define rs p << 1 | 1
#define lson p << 1, l, mid
#define rson p << 1 | 1, mid + 1, r
#define ll long long
using namespace std;
struct seg {
    ll tr[400005];
    void push_up(ll p) { tr[p] = tr[ls] + tr[rs]; }
    void update(ll p, ll l, ll r, ll aim) {
        if (l == r && l == aim) {
            tr[p] ^= 1;
            return;
        }
        ll mid = (l + r) >> 1;
        if (aim <= mid)
            update(lson, aim);
        if (mid < aim)
            update(rson, aim);
        push_up(p);
    }
    ll query(ll p, ll l, ll r, ll l_x, ll r_x) {
        if (l_x <= l && r <= r_x)
            return tr[p];
        ll re = 0, mid = (l + r) >> 1;
        if (l_x <= mid)
            re += query(lson, l_x, r_x);
        if (mid < r_x)
            re += query(rson, l_x, r_x);
        return re;
    }
} z, h;
int main() {
    ll n, m, q, op, x, y, x1, y1, x2, y2;
    scanf("%lld %lld %lld", &n, &m, &q);
    for (ll i = 1; i <= q; i++) {
        scanf("%lld", &op);
        if (op == 1) {
            scanf("%lld %lld", &x, &y);
            h.update(1, 1, n, x);
            z.update(1, 1, m, y);
        } else {
            scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
            ll re1 = z.query(1, 1, m, y1, y2), re2 = h.query(1, 1, n, x1, x2);
            printf("%lld\n", (x2 - x1 + 1) * re1 + (y2 - y1 + 1) * re2 - re1 * re2 * 2);
        }
    }
    return 0;
}
