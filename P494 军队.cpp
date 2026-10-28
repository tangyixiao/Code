#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, i, op, p, q, id;
long long bx[N], by[N], dx[N], dy[N];
long long u0x, u0y, u1x, u1y, ux, uy;
int fl[N];

signed main() {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%lld %lld", &bx[i], &by[i]);
    }
    while (m > 0) {
        m--;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d", &p, &q);
            u0x += p;
            u0y += q;
            u1x += q;
            u1y += p;
        } else if (op == 2) {
            scanf("%d", &id);
            if (fl[id] == 0) {
                dx[id] += u0x - u1x;
                dy[id] += u0y - u1y;
                fl[id] = 1;
            } else {
                dx[id] += u1x - u0x;
                dy[id] += u1y - u0y;
                fl[id] = 0;
            }
        } else {
            scanf("%d", &id);
            if (fl[id] == 0) {
                ux = u0x + dx[id];
                uy = u0y + dy[id];
                printf("%lld %lld\n", bx[id] + ux, by[id] + uy);
            } else {
                ux = u1x + dx[id];
                uy = u1y + dy[id];
                printf("%lld %lld\n", by[id] + uy, bx[id] + ux);
            }
        }
    }
    return 0;
}
