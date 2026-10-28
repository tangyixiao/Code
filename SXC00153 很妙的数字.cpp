#include <bits/stdc++.h>
using namespace std;
const int M = 2521;
int dv[55], nd, pos[2521], L, i;
int dg[25];
long long memo[25][55][M];
bool seen[25][55][M];
int gcd2(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
long long go(int r, int li, int rem) {
    if (r == 0) {
        return (rem % dv[li] == 0) ? 1 : 0;
    }
    if (seen[r][li][rem]) {
        return memo[r][li][rem];
    }
    seen[r][li][rem] = true;
    long long s = 0;
    for (int v = 0; v <= 9; v++) {
        int nl = li;
        if (v > 0) {
            nl = pos[dv[li] / gcd2(dv[li], v) * v];
        }
        s += go(r - 1, nl, (rem * 10 + v) % M);
    }
    memo[r][li][rem] = s;
    return s;
}
long long cnt(long long x) {
    if (x < 1) {
        return 0;
    }
    L = 0;
    long long t = x;
    while (t > 0) {
        dg[L++] = t % 10;
        t /= 10;
    }
    for (i = 0; i < L / 2; i++) {
        int tp = dg[i];
        dg[i] = dg[L - 1 - i];
        dg[L - 1 - i] = tp;
    }
    long long res = 0;
    int li = 1, rem = 0;
    for (int p = 0; p < L; p++) {
        for (int v = 0; v < dg[p]; v++) {
            int nl = li;
            if (v > 0) {
                nl = pos[dv[li] / gcd2(dv[li], v) * v];
            }
            res += go(L - p - 1, nl, (rem * 10 + v) % M);
        }
        if (dg[p] > 0) {
            li = pos[dv[li] / gcd2(dv[li], dg[p]) * dg[p]];
        }
        rem = (rem * 10 + dg[p]) % M;
    }
    if (rem % dv[li] == 0) {
        res++;
    }
    return res - 1;
}
signed main() {
    nd = 0;
    for (int a = 1; a <= M; a++) {
        if (M % a == 0) {
            dv[nd] = a;
            pos[a] = nd;
            nd++;
        }
    }
    int T;
    long long l, r;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", cnt(r) - cnt(l - 1));
    }
    return 0;
}
