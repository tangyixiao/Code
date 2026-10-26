#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long MOD = 1e9 + 7;
long long n, i, x, l, c1, c2, s1, s2, cur;
long long t1[N], t2[N];
void add(long long *t, int p, long long v) {
    for (; p < N; p += p & -p) {
        t[p] += v;
    }
}
long long que(long long *t, int p) {
    long long s = 0;
    for (; p > 0; p -= p & -p) {
        s += t[p];
    }
    return s;
}
signed main() {
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &x);
        c1 = que(t1, x), s1 = que(t2, x);
        c2 = i - 1 - c1, s2 = l - s1;
        cur = (c1 * x - s1 + s2 - c2 * x) % MOD;
        cur = (cur % MOD + MOD) % MOD;
        l += x;
        add(t1, x, 1), add(t2, x, x);
        if (i > 1) {
            printf(" ");
        }
        printf("%lld", cur);
    }
    printf("\n");
    return 0;
}
