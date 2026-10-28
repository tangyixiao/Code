#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
long long a[N][N], cs[N];
int best[N], n, m, A, B, i, j, r, p;
long long lo, hi, mid, tot;
int cntok(long long x) {
    int c = 0, i;
    long long acc = 0;
    for (i = 1; i <= m; i++) {
        acc += cs[i];
        if (acc >= x) {
            c++;
            acc = 0;
        }
    }
    return c;
}
int check(long long x) {
    int feasible;
    for (j = 1; j <= m; j++) {
        cs[j] = 0;
    }
    p = 1, best[0] = 0;
    for (r = 1; r <= n; r++) {
        for (j = 1; j <= m; j++) {
            cs[j] += a[r][j];
        }
        while (p < r) {
            for (j = 1; j <= m; j++) {
                cs[j] -= a[p][j];
            }
            if (cntok(x) >= B) {
                p++;
            } else {
                for (j = 1; j <= m; j++) {
                    cs[j] += a[p][j];
                }
                break;
            }
        }
        feasible = cntok(x) >= B;
        if (feasible) {
            best[r] = best[p - 1] + 1;
        } else {
            best[r] = -1000000;
        }
    }
    return best[n] >= A;
}
signed main() {
    scanf("%d%d%d%d", &n, &m, &A, &B);
    tot = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%lld", &a[i][j]);
            tot += a[i][j];
        }
    }
    lo = 0, hi = tot;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    printf("%lld\n", lo);
    return 0;
}
