#include <bits/stdc++.h>
using namespace std;
long long m, n, p, r, q;
signed main() {
    scanf("%lld%lld", &m, &n);
    p = 2 * (3 * m - 1);
    r = (n - 1) % p;
    if (r < 3 * m) {
        q = r + 1;
    } else {
        q = 2 * 3 * m - r - 1;
    }
    q = (q - 1) % 3;
    if (q == 0) {
        printf("lan\n");
    } else if (q == 1) {
        printf("huang\n");
    } else {
        printf("hong\n");
    }
    return 0;
}
