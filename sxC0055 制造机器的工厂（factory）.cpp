#include <bits/stdc++.h>
using namespace std;
long long n, x, b, s, m;
signed main() {
    scanf("%lld%lld%lld%lld%lld", &n, &x, &b, &s, &m);
    __int128 parts = (__int128)n * x + (__int128)n * (n - 1) / 2;
    __int128 total = (__int128)m * (b + 2 * s);
    printf("%lld\n", (long long)(total / parts));
    return 0;
}
