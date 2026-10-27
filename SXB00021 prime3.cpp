#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, i, j, p[N], cnt;
long long e, t;
signed main() {
    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        p[i] = 1;
    }
    for (i = 2; (long long)i * i <= n; i++) {
        if (p[i]) {
            for (j = i * i; j <= n; j += i) {
                p[j] = 0;
            }
        }
    }
    for (i = 2; i <= n; i++) {
        if (!p[i]) {
            continue;
        }
        e = 0;
        for (t = i; t <= n; t *= i) {
            e += n / t;
        }
        printf("%d %lld\n", i, e);
    }
    return 0;
}
