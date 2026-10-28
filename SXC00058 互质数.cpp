#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long T, A, B, n, i, j, pr[N], pc, p[N], ans;
long long f(long long x) {
    long long r = 0;
    for (int s = 0; s < (1 << pc); s++) {
        long long d = 1;
        int b = 0;
        for (j = 0; j < pc; j++) {
            if (s >> j & 1) {
                d *= pr[j], b++;
            }
        }
        if (b & 1) {
            r -= x / d;
        } else {
            r += x / d;
        }
    }
    return r;
}
signed main() {
    if (fopen("coprime.in", "r")) {
        freopen("coprime.in", "r", stdin);
        freopen("coprime.out", "w", stdout);
    }
    scanf("%lld", &T);
    for (long long t = 1; t <= T; t++) {
        scanf("%lld%lld%lld", &A, &B, &n);
        pc = 0;
        long long m = n;
        for (i = 2; i * i <= m; i++) {
            if (m % i == 0) {
                pr[pc++] = i;
                while (m % i == 0) {
                    m /= i;
                }
            }
        }
        if (m > 1) {
            pr[pc++] = m;
        }
        ans = f(B) - f(A - 1);
        printf("Case #%lld: %lld\n", t, ans);
    }
    return 0;
}
