#include <bits/stdc++.h>
using namespace std;
long long X, Y, K, B, i, j, r;
long long C[70][70], pw[70][70];
long long cnt(long long x) {
    if (x < 1) {
        return 0;
    }
    int d[70], len = 0;
    long long t = x;
    while (t > 0) {
        d[len++] = t % B;
        t /= B;
    }
    for (int a = 0; a < len / 2; a++) {
        int tmp = d[a];
        d[a] = d[len - 1 - a];
        d[len - 1 - a] = tmp;
    }
    long long res = 0;
    int used = 0;
    for (int p = 0; p < len; p++) {
        int rest = len - p - 1;
        for (int v = 0; v < d[p]; v++) {
            int nu = used + (v != 0 ? 1 : 0);
            if (nu > K) {
                continue;
            }
            int need = K - nu;
            if (need < 0 || need > rest) {
                continue;
            }
            res += C[rest][need] * pw[B - 1][need];
        }
        if (d[p] != 0) {
            used++;
        }
        if (used > K) {
            break;
        }
    }
    if (used == K) {
        res++;
    }
    return res;
}
signed main() {
    scanf("%lld %lld %lld %lld", &X, &Y, &K, &B);
    for (i = 0; i <= 65; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + (j <= i - 1 ? C[i - 1][j] : 0);
        }
    }
    pw[0][0] = 1;
    for (i = 1; i <= 65; i++) {
        pw[i][0] = 1;
        for (j = 1; j <= 65; j++) {
            pw[i][j] = pw[i][j - 1] * i;
        }
    }
    printf("%lld\n", cnt(Y) - cnt(X - 1));
    return 0;
}
