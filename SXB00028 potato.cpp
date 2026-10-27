#include <bits/stdc++.h>
using namespace std;
long long a, b, n, m, k, best, cost, y, i, j, d, k0, lo, hi, md, J;
long long cal(long long k) {
    long long y = k + k / m;
    if (y > n) {
        y = n;
    }
    return k * a + (n - y) * b;
}
signed main() {
    if (fopen("potato.in", "r")) {
        freopen("potato.in", "r", stdin);
        freopen("potato.out", "w", stdout);
    }
    scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
    best = n * b;
    lo = 0, hi = n;
    for (; lo < hi;) {
        md = (lo + hi) / 2;
        if (md + md / m >= n) {
            hi = md;
        } else {
            lo = md + 1;
        }
    }
    k0 = lo;
    for (k = k0 - 1; k <= k0; k++) {
        if (k < 0 || k > n) {
            continue;
        }
        cost = cal(k);
        if (cost < best) {
            best = cost;
        }
    }
    J = n > 1 ? (n - 1) / (m + 1) : 0;
    for (j = J - 3; j <= J + 3; j++) {
        for (d = -1; d <= 1; d++) {
            k = j * m + d;
            if (k < 0 || k > n) {
                continue;
            }
            cost = cal(k);
            if (cost < best) {
                best = cost;
            }
        }
    }
    for (k = 0; k <= 2; k++) {
        if (k > n) {
            continue;
        }
        cost = cal(k);
        if (cost < best) {
            best = cost;
        }
    }
    printf("%lld\n", best);
    return 0;
}
