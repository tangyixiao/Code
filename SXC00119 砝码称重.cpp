#include <bits/stdc++.h>
using namespace std;
long long a, b, c, g, A, B, C, u0, v0, u, v, bu, bv, t, t1, t2, i, k;
long long ax, ay;
long long ex(long long x, long long y) {
    if (y == 0) {
        u0 = 1, v0 = 0;
        return x;
    }
    long long d = ex(y, x % y);
    long long p = u0, q = v0;
    u0 = q, v0 = p - (x / y) * q;
    return d;
}
void upd(long long w) {
    long long x = u0 * C + w * B, y = v0 * C - w * A;
    long long s = (x < 0 ? -x : x) + (y < 0 ? -y : y);
    long long ws = a * (x < 0 ? -x : x) + b * (y < 0 ? -y : y);
    if (s < ax || (s == ax && ws < ay)) {
        ax = s, ay = ws, bu = x < 0 ? -x : x, bv = y < 0 ? -y : y;
    }
}
signed main() {
    for (; scanf("%lld%lld%lld", &a, &b, &c) == 3;) {
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        g = ex(a, b);
        A = a / g, B = b / g, C = c / g;
        ax = 4000000000000000000LL, ay = ax, bu = 0, bv = 0;
        t1 = (-u0 * C) / B;
        t2 = (v0 * C) / A;
        for (i = -3; i <= 3; i++) {
            upd(t1 + i);
            upd(t2 + i);
        }
        upd(0);
        printf("%lld %lld\n", bu, bv);
    }
    return 0;
}
