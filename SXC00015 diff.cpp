#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n, i, s, t;
long long a[N], b[N], f[N][3];
signed main() {
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    f[1][0] = 0, f[1][1] = b[1], f[1][2] = b[1];
    for (i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            f[i][j] = 1e18;
            long long vj = a[i] + (j == 0 ? 0 : (j == 1 ? 1 : -1));
            long long cj = (j == 0 ? 0 : b[i]);
            for (int k = 0; k < 3; k++) {
                long long vk = a[i - 1] + (k == 0 ? 0 : (k == 1 ? 1 : -1));
                if (vk != vj) {
                    f[i][j] = min(f[i][j], f[i - 1][k] + cj);
                }
            }
        }
    }
    s = min(f[n][0], min(f[n][1], f[n][2]));
    printf("%lld\n", s);
    return 0;
}
