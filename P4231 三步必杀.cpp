#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
const int N = 1e7 + 5;
int n, m;
ll c[N];
int main() {
    scanf("%d%d", &n, &m);
    ll a = 0, b = 0, s, t, d, Max = 0, Xor = 0;
    for (int L, R; m--;) {
        scanf("%d%d%lld%lld", &L, &R, &s, &t);
        d = (t - s) / (R - L);
        c[L] += s, c[L + 1] += d - s;
        c[R + 1] -= d + t, c[R + 2] += t;
    }
    for (int i = 1; i <= n; ++i)
        Max = max(Max, a += (b += c[i])), Xor ^= a;
    printf("%lld %lld", Xor, Max);
    return 0;
}
