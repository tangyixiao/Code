#include <bits/stdc++.h>
using namespace std;

long long k, a, b, n, cnt, s;

signed main() {
    if (fopen("coffin.in", "r")) {
        freopen("coffin.in", "r", stdin);
        freopen("coffin.out", "w", stdout);
    }
    scanf("%lld%lld%lld", &k, &a, &b);
    cnt = 0;
    for (s = 1; s <= 1539; s++) {
        if (k > b / s) {
            break;
        }
        n = k * s;
        if (n < a) {
            continue;
        }
        long long t = n, f = 0;
        while (t > 0) {
            long long r = t % 10;
            f += r * r;
            t /= 10;
        }
        if (f == s) {
            cnt++;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
