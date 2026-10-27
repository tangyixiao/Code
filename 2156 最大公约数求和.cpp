#include <bits/stdc++.h>
using namespace std;
long long n, i, ans;
long long phi(long long x) {
    long long r = x, p;
    for (p = 2; p * p <= x; p++) {
        if (x % p == 0) {
            r = r / p * (p - 1);
            while (x % p == 0) {
                x /= p;
            }
        }
    }
    if (x > 1) {
        r = r / x * (x - 1);
    }
    return r;
}
signed main() {
    scanf("%lld", &n);
    ans = 0;
    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans += i * phi(n / i);
            if (i != n / i) {
                ans += (n / i) * phi(i);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
