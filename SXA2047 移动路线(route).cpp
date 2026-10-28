#include <bits/stdc++.h>
using namespace std;
const int N = 25;
long long m, n, i, j, f[N][N];
signed main() {
    scanf("%lld%lld", &m, &n);
    for (i = 1; i <= m; i++) {
        f[i][1] = 1;
    }
    for (j = 1; j <= n; j++) {
        f[1][j] = 1;
    }
    for (i = 2; i <= m; i++) {
        for (j = 2; j <= n; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    printf("%lld\n", f[m][n]);
    return 0;
}
