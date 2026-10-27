#include <bits/stdc++.h>
using namespace std;
long long k, i, x, y, kk;
signed main() {
    scanf("%lld", &k);
    kk = k * k;
    for (i = 1; i <= k; i++) {
        if (kk % i != 0) {
            continue;
        }
        x = k + i;
        y = k + kk / i;
        printf("1/%lld=1/%lld+1/%lld\n", k, x, y);
    }
    return 0;
}
